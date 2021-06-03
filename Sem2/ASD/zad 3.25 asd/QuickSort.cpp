#include <iostream>
using namespace std;
const int N = 9; //zmienna stala globalna

void wypisz(int* tab)
{
	for (int i = 0; i < N; i++) //mozemy tak zrobic bo N jest widoczna dla wszystkich
		cout << tab[i] << " ";
}

void quick_sort(int* tab, int l, int  p)	//  l - lewo , p - prawo  [wskazujemy w ktorym miejscu jestesmy w tablicy]
{
	if (p <= l) return; //konczymy jesli indeksy wskazujace sie "omina" [ale te uzyskane poprzez pocwiartowanie nasza rekurencja]
	int lewy = l - 1;	//wychodzimy o jeden przed tablice
	int prawy = p + 1;	//wychodzimy o jeden za tablice
	int srodek = tab[(lewy + prawy)/2]; //znajdujemy srodek w naszej tablicy i ja zapisujemy (zawsze jakis znajdziemy bo mamy zmienna typu int wiec utnie koncowke)

	while (true)	//nieskoczona petla [wyjdziemy uzywajac break]
	{
		while (srodek > tab[++lewy]); //przesuwamy sie po elementach tablicyy szukajac mniejszego niz "srodek" [ ++ lewy] zeby najpierw dodac wartosc do lewy (inaczej bylbysmy poza tablica)
		while (srodek < tab[--prawy]); //to samo tylko w prawo
		if (lewy <= prawy)
			swap(tab[lewy], tab[prawy]);   //jesli indeksy lewego i prawego "nie napotkaly sie" to zamieniamy wartosci w tablicach miejscami
		else
			break; //natomiast jesli przejda przez siebie to wychodzimy z petli
	}
	if (prawy > l)	//jezeli indeks ktorych chodzilismy po tablic (zaczynajacy od prawej strony) jest wiekszy niz ten z lewej
		quick_sort(tab, l, prawy);	//wywolujemy quicksort z lewej strony ograniczajac o "nowy prawy" indeks (tak jakbysmy zmienjszali tablice)
	if (lewy < p)
		quick_sort(tab, lewy, p);	//wywolujemy quicksort z prawej strony , naszym poczatkiem bedzie "Nowy lewy" indeks, a prawy zostanie bez zmian
}

int main()
{
	int tab[N] = { 27, 10, 12, 20, 10, 25, 13, 15, 22 }; //uzywamy tych samych danych co w poprzednich zajeciach
	cout << "Algorytm sortowania szybkiego!!" << endl;

	quick_sort(tab, 0, N - 1);   //startujemy przypisujac lewo = 0  i prawo  "maksymalnie na prawo" czyli n-1
	wypisz(tab);
	return 0;
}
