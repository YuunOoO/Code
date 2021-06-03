#include <iostream>

using namespace std;

const int N = 7;

void wypisz_podciag (int tab[N], int x, int y)
{
    for (int i = x; i < x + y-1;i++)
        cout << tab[i];
    return;
}

int main()
{
    int tab[N] = { 2,4,6,7,8,5,1 };
    int k;
    cout << "Podaj k: ";
    cin >> k;
    int j = k-1;        //ogranicznik
    if (k >= 2)
    {
        for (int i = 0; i < N;i++)          //kolejnosc nie ma znaczenia wiec mozemy zrobic to przepisujac podciag i dodajc na koniec inny element z pozostalych
        {

            for (int q = j; q < N; q++)      //ile elementowy generujemy
            {
                wypisz_podciag(tab, i, k);  //przepisujemy podciag
                cout << tab[q] << endl;         //dopisujemy koncowke
            }
            j++;    //przechodzimi o kolumne dalej
        }
    }
    else
    {
        if (k == 1)
            for (int i = 0; i < N;i++)
                cout << tab[i] << endl;
        else
            cout << "{} zbior pusty";
    }
}
//zlozonosc pesymistyczna n^2 * k
