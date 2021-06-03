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
void ustaw(int** tab, int n, vec v, int klocek, int srodekx, int srodeky, int x)
{
	if (n == 1)
	{
		if (v.x >srodekx && v.x <= x && v.y <= srodeky && v.y <= x && v.y>=0 && v.x>=0)
		{
			//klocek = ktory();
			if (tab[v.x][v.y+1] == 0)
				tab[v.x][v.y + 1] = klocek;
			if (tab[v.x + 1][v.y] == 0)
				tab[v.x + 1][v.y] = klocek;			
			if (tab[v.x + 1][v.y + 1] == 0)	
				tab[v.x + 1][v.y + 1] = klocek;
		}
		else if (v.x <= srodekx && v.x <= x && v.y <= srodeky && v.y <= x && v.y >= 0 && v.x >= 0)
		{
			//klocek = ktory();
			if (tab[v.x][v.y + 1] == 0)
				tab[v.x][v.y + 1] = klocek;
			if (tab[v.x - 1][v.y] == 0)
				tab[v.x - 1][v.y] = klocek;
			if (tab[v.x -1][v.y + 1] == 0)
				tab[v.x -1][v.y + 1] = klocek;
		}
		else if (v.x <= srodekx && v.x <= x && v.y > srodeky && v.y <= x && v.y >= 0 && v.x >= 0)
		{
			//klocek = ktory();
			if (tab[v.x-1][v.y] == 0)
				tab[v.x-1][v.y] = klocek;
			if (tab[v.x - 1][v.y-1] == 0)
				tab[v.x - 1][v.y-1] = klocek;
			if (tab[v.x][v.y - 1] == 0)
				tab[v.x][v.y - 1] = klocek;
		}
		else if (v.x > srodekx && v.x <= x && v.y > srodeky && v.y <= x && v.y >= 0 && v.x >= 0)
		{
			//klocek = ktory();
			if (tab[v.x + 1][v.y] == 0)
				tab[v.x + 1][v.y] = klocek;
			if (tab[v.x + 1][v.y + 1] == 0)
				tab[v.x + 1][v.y + 1] = klocek;
			if (tab[v.x][v.y + 1] == 0)
				tab[v.x][v.y + 1] = klocek;
		}
		return;
	}
	else
	{
		//klocek = ktory();
		tab[srodekx][srodeky] = klocek;
		tab[srodekx + 1][srodeky] = klocek;
		tab[srodekx][srodeky + 1] = klocek;
		tab[srodekx + 1][srodeky + 1] = klocek;
		if (v.x <= srodekx)
			if (v.y <= srodeky)
				tab[srodekx][srodeky] = 0;
			else
				tab[srodekx][srodeky + 1] = 0;
		else
			if (v.y <= srodeky)
				tab[srodekx + 1][srodeky] = 0;
			else
				tab[srodekx + 1][srodeky + 1] = 0;

		vec L1, L2, L3, L4;
		L1.x = srodekx, L1.y = srodeky;
		L2.x = srodekx + 1, L2.y = srodeky;
		L3.x = srodekx, L3.y = srodeky + 1;
		L4.x = srodekx + 1, L4.y + srodeky + 1;
		ustaw(tab, n - 1, L1, klocek + 1, srodekx / 2, srodeky / 2, x);
		ustaw(tab, n - 1, L2, klocek + 1, srodekx * 3 / 2 + 1, srodeky / 2, x);
		ustaw(tab, n - 1, L3, klocek + 1, srodekx / 2, srodeky * 3 / 2+1 , x);
		ustaw(tab, n - 1, L4, klocek + 1, srodekx * 3 / 2 + 1, srodeky * 3 / 2+1 , x);
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
	int srodek = x / 2 - 1;



	wypisywanie(tab, x);
	cout << endl;

	ustaw(tab, n, v0, 1, srodek, srodek , x-1);

	wypisywanie(tab, x);


}
