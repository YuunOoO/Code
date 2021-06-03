#include <iostream>
using namespace std;

const int N = 8;	//ustalamy sobie stala dlugosc tablicy

void heapyfi(int tab[], int i, int rozmiar)	//przywracamy wlasciwosc kopca
{
	int max;
	int lewy = 2 * i;	//ustawiawmy lewego syna wedlug reguly 
	int prawy = 2 * i + 1;	//ustwiamy prawego syna

	if (lewy <= rozmiar && tab[lewy] > tab[i])	//jezeli nie wyszlismy poza tablice i lewy syn jest wiekszy od ojca
		max = lewy;	//to ustawiam index max na lewy
	else
		max = i; //jesli nie to max zostaje tam gdzie byl

	if (prawy <= rozmiar && tab[prawy] > tab[max])	//to samo sprawdzamy dla prawego syna
		max = prawy;	//wiec jesli zostanie wykonana instrukcja to prawy jest najwiekszy

	if (max != i)	//jesli maxem nie jest ojciec
	{
		swap(tab[i], tab[max]);	//to zamienimay go z dzieckiem ktore bylo wieksze
		heapyfi(tab, max, rozmiar);	//wywolemy funkcje z parametrem max
	}
}

void buduj(int tab[],int n)	//budujemy kopiec
{
	int rozmiar = n;	//ustalamy rozmiar (moznaby to pominac i napisac n 
	for (int i = (n/2) ;i >= 0;i--)	 
		heapyfi(tab, i, rozmiar);	//wywolujemy przywracanie wlasciwosci kopca
}

void sortuj(int tab[], int n)	//funkcja sortujaca
{
	buduj(tab, n);	//budujemy kopiec
	int size = n;
	while (size>0)	// przechodzimy przez poszczegolne elementy
	{
		swap(tab[0], tab[size]); //zamieniamy je
		size--;	//zmniejszamy indeks
		heapyfi(tab, 0, size);	//wywyolujemy przywracanie wlasciwosci kopca
	}

}
void wypisz(int tab[])	//wypisywanie
{
	for (int i = 0; i < N; i++)
		cout << tab[i] << endl;
}
int main()
{
	int tab[N] = { 10, 12, 20, 10, 25, 13, 15, 22};	//deklarujemy tablice
	cout << "algorytm kopcowania !!!"<<endl;
	
	wypisz(tab);	//wypisujemy przed sortowaniem
	sortuj(tab, N-1);	//sortujemy 
	cout << "-----------" << endl;
	wypisz(tab);	//wypisujemy ponownie

}

