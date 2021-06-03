#include <iostream>

using namespace std;

const int N = 9;

int main()
{
    int tab[N] = { 27, 10, 12, 20, 10, 25, 13, 15, 22 };
    int j;
    cout << "Algorytm sortowania przez wstawianie!!" << endl;


    for (int i = 1; i < N; i++)             //algorytm
    {
        int tmp = tab[i]; //zachowujemy element 
        j = i - 1;
        while (j >= 0 && tab[j] > tmp) //jesli nasz element jest mniejszy niz poprzedni element z posortowanego ciagu
        {
            tab[j + 1] = tab[j];   // przesuwanie elementow tablicy do przodu [ zeby zrobic taka luke gdzie mozemy wrzucic ten nasz tmp ]
            j--;
        }
        tab[j + 1] = tmp; //wstawiamy nasza zapamietana tablice w luke 

    }

    for (int i = 0;i < N;i++)   //wyswietlanie
        cout << tab[i] << endl;
}
