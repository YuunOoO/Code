#include <iostream>

using namespace std;

const int N = 13;


int main()
{

    int tab[N] = { 1,2,4,5,4,2,7,5,5,5,4,1,2};         //tablica robocza
    int p = N;
    for (int i = 0; i < p; i++)
    {
        int j = i+1;

        while (j < p )
        {
            if (tab[j] == tab[i])  //sprawdzamy czy liczba sie powtarza
            {
                tab[j] = tab[p];        //"zamieniamy" tablice koncowa z aktualna
                p--;    //skracamy zakres tablicy -> liczba wypada poza zakres
                j--;
            }
            j++;
        }

    }
    for (int i = 0; i < p; i++) //wypisywanie
        cout << tab[i] << " ";

}

// zlozonosc (pesymistyczna) N^2

