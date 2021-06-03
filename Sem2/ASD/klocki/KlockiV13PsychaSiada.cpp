#include <iostream>
using namespace std;
struct vec	//struktura wektorowa
{
	int x; //polozenie x na planszy
	int y;	// polozenie y na planszy
}v0;

int pot(int n) //funkcja wyliczajaca potege 2^n
{
	int k = 2;
	for (int i = 1; i < n; i++)
		k *= 2;
	return k;
}
void ustaw(int** tab, int n, vec v, int klocek, int a, int b, int x, int y)	//moznaby bylo przesylac 3 wektory ale tak jest bardziej czytelne
{
	if (n == 1)	//przypadek koncowy, gdy plansze maja wymiary 2x2 
	{
		//wybieramy w ktorej cwiartce znajduje sie nasza kostka poprzez rozpoznanie gdzie znajduje sie juz wypelnione pole
		if (tab[a+1][b+1]!=0)  // II	cwiartka
		{
				tab[a][b] = klocek;				//kladziemy ta kostke
				tab[a + 1][b] = klocek;
				tab[a][b + 1] = klocek;
		}
		else if (tab[a][b+1]!=0) //I cwiartka
		{
				tab[a][b] = klocek;
				tab[a + 1][b] = klocek;
				tab[a + 1][b + 1] = klocek;
		}
		else if (tab[a+1][b]!=0)// III cwiartka
		{
				tab[a][b] = klocek;
				tab[a][b + 1] = klocek;
				tab[a + 1][b + 1] = klocek;
		}
		else if (tab[a][b]!=0) //IV cwiartka
		{
				tab[a + 1][b] = klocek;
				tab[a][b + 1] = klocek;
				tab[a + 1][b + 1] = klocek;
		}
		return; //wracamy do reszty programu
	}
	else
	{
		int prevx = a; //musimy zapisac sobie poczatkowe wspolrzedne (lewy gorny rog)
		int prevy = b;

		a = (x + a) / 2;	//znajdujemy srodek (srodek X)
		b = (y + b) / 2;	//(srodek Y)

		vec L1, L2, L3, L4;	//przypisujemy wspolrzedne naszym klockom
		L1.x = a, L1.y = b;				//I cwiartka
		L2.x = a + 1, L2.y = b;			//II cwiartka
		L3.x = a, L3.y = b + 1;			//III cwiartka
		L4.x = a + 1, L4.y = b + 1;		//IV cwiartka
		//mamy nadmiar jednej wspolrzednej klocka wiec musimy sie go pozbyc i ustawic te na wlasciwym miejscu
		if (v.y <= b)				//algorytm ustalania polozenia nowego klocka po podzieleniu planszy
		{
			tab[a][b + 1] = klocek;
			tab[a + 1][b + 1] = klocek;
			if (v.x <= a)
			{
				tab[a + 1][b] = klocek;
				L1.x = v0.x, L1.y = v0.y;	//trzeba uwzglednic wspolrzedne kostki ktora wczesniej dostalismy z v0
			}
			else
			{
				tab[a][b] = klocek;
				L2.x = v0.x, L2.y = v0.y; //to samo
			}

		}
		else
		{

			tab[a][b] = klocek;
			tab[a + 1][b] = klocek;
			if (v.x <= a)
			{
				tab[a + 1][b + 1] = klocek;
				L3.x = v0.x, L3.y = v0.y; //to samo
			}
			else
			{
				tab[a][b + 1] = klocek;
				L4.x = v0.x, L4.y = v0.y; // to samo
			}

		}
		//dzielimy nasza plansze wywolywujac rekurencyjnie nasz mniejsze podzadania dla :
		ustaw(tab, n - 1, L1, klocek + 1, prevx, prevy, a, b); //II cwiartka
		ustaw(tab, n - 1, L2, klocek + 1, a + 1, prevy, x, b);	//I cwiartka
		ustaw(tab, n - 1, L3, klocek + 1, prevx, b + 1, a, y);	//III cwiartka
		ustaw(tab, n - 1, L4, klocek + 1, a + 1, b + 1, x, y); //IV cwiartka
	}

}
void wypisywanie(int** tab, int x)	//funkcja do wypisywania
{
	for (int i = 0;i < x;i++)
	{
		for (int k = 0;k < x;k++)
			cout << tab[k][i];
		cout << endl;
	}
}
int main()
{
	int n;
	cout << "Witaj w algorycmie ukladania wirtualnych kostek!" << endl;
	cout << "Podaj jak wielka ma byc plansza!(2^n) [Podajemy n]:  " << endl;
	cin >> n;
	cout << " Podaj wspolrzedne startowe [x,y]: " << endl;
	cin >> v0.x >> v0.y;
	int x = pot(n);
	cout << x << endl;
	int** tab = new int* [x];	//inicjalizujemy tablice tablic
	for (int i = 0;i < x;i++)	//generujemy nasze podtablicle
		tab[i] = new int[x];
	for (int i = 0;i < x;i++)
		for (int k = 0;k < x;k++)
			tab[i][k] = 0;	//zerujemy nasze wszystkie tablice

	tab[v0.x][v0.y] = 1;	//oznaczamy element startowy
	wypisywanie(tab, x); //wypisujemy przed ulozeniem
	cout << endl;
	ustaw(tab, n, v0, 2, 0, 0, x - 1, x - 1); //wywoluje funkcje ukladania z naszymi parametrami [tablica,rozmiar planszy 2^ .. (n), kostka (zaczynajac od 2 bo 1 juz wykorzystalismy,
	//wspolrzedne poczatku 0,0 i wspolrzedne konca x-1,x-1 )
	wypisywanie(tab, x); //wypisujemy po ulozeniu
	//Zlozonosc programu to glownie nasz podzial planszy ktory jest rowny log2(N), gdzie N oznacza dlugosc tablicy(N*N), wykonujemy rowniez na kazdym podziale 3 dodania kostek ->
	// 3* Log2(N), do tego dochodzi nasz algorytm ustawiania klocka na srodku planszy, ktory takze jest jakąs stałą przez która przemnozymy logarytm wiec w ostatecznym rozrachunku 
	// bedziemy miec zlozonosc rzedu Log2(N)
}
