#include <iostream>
using namespace std;
struct vec
{
	int x;
	int y;
}v0;

int pot(int n)
{
	int k = 2;
	for (int i = 1; i < n; i++)
		k *= 2;
	return k;
}
int counter = 2;
int ktory()
{
	counter++;
	return counter;
}
void ustaw(int** tab, int n, vec v, int klocek, int a, int b, int x, int y)
{
	if (n == 1)
	{
	//	if (v.x >= 0 && v.y >= 0 &&v.x<8 && v.y<8)
		//{
			if (v.x < x && v.y < y)  // II
			{
				tab[v.x][v.y + 1] = klocek;
				tab[v.x + 1][v.y] = klocek;
				tab[v.x + 1][v.y + 1] = klocek;
			}
			else if (v.x >= x && v.y < y)
			{
				tab[v.x][v.y + 1] = klocek;
				tab[v.x - 1][v.y] = klocek;
				tab[v.x - 1][v.y + 1] = klocek;
			}
			else if (v.x < x && v.y >= y)// III
			{
				tab[v.x + 1][v.y] = klocek;
				tab[v.x + 1][v.y - 1] = klocek;
				tab[v.x][v.y - 1] = klocek;
			}
			else if (v.x >= x && v.y >= y) //IV
			{
				tab[v.x - 1][v.y] = klocek;
				tab[v.x - 1][v.y - 1] = klocek;
				tab[v.x][v.y - 1] = klocek;
			}
		//}
		return;
	}
	else
	{
		a = (x + a) / 2;
		b = (y + b) / 2;

		if (v.y <= b)
		{
			tab[a][b + 1] = klocek;
			tab[a + 1][b + 1] = klocek;
			if (v.x <= a)
				tab[a + 1][b] = klocek;
			else
				tab[a][b] = klocek;
		}
		else
		{

			tab[a][b] = klocek;
			tab[a + 1][b] = klocek;
			if (v.x <= a)
				tab[a][b + 1] = klocek;
			else
				tab[a + 1][b + 1] = klocek;
		}

		vec L1, L2, L3, L4;
		L1.x = a, L1.y = b;
		L2.x = a + 1, L2.y = b;
		L3.x = a, L3.y = b + 1;
		L4.x = a + 1, L4.y = b + 1;
		ustaw(tab, n - 1, L1, klocek + 1, 0, 0, a, b); //II cwiartka
		ustaw(tab, n - 1, L2, klocek + 1, a + 1, b, x, 0);	//I
		ustaw(tab, n - 1, L3, klocek + 1, a, b + 1, 0, y);	//III
		ustaw(tab, n - 1, L4, klocek + 1, a + 1, b + 1, x, y); //IV
	}

}
void wypisywanie(int** tab, int x)
{
	for (int i = 0;i < x;i++)
	{
		for (int k = 0;k < x;k++)
			cout << tab[i][k];
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



	wypisywanie(tab, x);
	cout << endl;
	ustaw(tab, n, v0, 2, 0, 0, x - 1, x - 1);

	wypisywanie(tab, x);


}
