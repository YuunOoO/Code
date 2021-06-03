#include <iostream>

using namespace std;

const int N = 9;


int main()
{
    int tab[N] = { 27, 10, 12, 20, 10, 25, 13, 15, 22 };
    int j,tmp;

    for (int i = 0; i < N-1; i++)             //do ktorego miejsca jest posortowane
    {
        int idx=i; // musimy zachowac indeks
        for (int j = i + 1;j < N;j++) //szukamy najmniejszego elementu
            if (tab[j] < tab[idx]) // jak znajdziemy 
                idx = j;    //to oznaczamy indeks ktory to jest element , ktory chcemy podmienic
        tmp = tab[i];   //operacja podmieniania
        tab[i] = tab[idx];
        tab[idx] = tmp;
        
    }

    for (int i = 0;i < N;i++)   //wyswietlanie
        cout << tab[i] << endl;
}

