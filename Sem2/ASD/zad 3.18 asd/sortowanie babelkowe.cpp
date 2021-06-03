#include <iostream>
using namespace std;

const int N = 9;

int main()
{
	int tmp;
	int tab[N] = { 27, 10, 12, 20, 10, 25, 13, 15, 22 };

	for (int i = 0; i < N; i++) // ktora liczbe sprawdzamy
	{
		for (int k = 0; k < N-1;k++) //z ktorymi liczbami ja porownujemu
		{
			if (tab[k] > tab[k + 1])    //porownanie
			{
				int tmp = tab[k + 1];   //zamiana [mozna uzyc swap]
				tab[k + 1] = tab[k];
				tab[k] = tmp;
			}

		}

	}

	//wyswietlanie
	for (int i = 0;i < N;i++)
		cout << tab[i] << endl;

}
