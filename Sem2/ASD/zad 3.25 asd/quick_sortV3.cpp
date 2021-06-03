#include <iostream>

using namespace std;

const int N = 8;

void wypisz(int* tab) //wypisywanie
{
    for (int i = 0; i < N; i++)
        cout << tab[i] << endl;
}

void zamien(int* a, int* b) //funkcja zamiany
{
    int tmp  = *a;
    *a = *b;
    *b = tmp;
}

int podzial(int* tab, int maly, int duzy)
{
    int  pivot_var = tab[duzy]; //przypisujemy wartosc tablicy wiekszego elementu o do pivota;
    int sciana = maly ; //oraz  ustalamy nasza granice

    for (int i = maly ; i < duzy; i++) //dopóki nie upewnimy sie ze pivot jest w wlasciwym miejscu
    {
        if (tab[i] <= pivot_var) //jezeli aktualny element jest mniejszy lub rowny pivotowi
        {
            zamien(&tab[i], &tab[sciana]); //zamiana z pierwszym elementem przed granica
            sciana++; //przesuwamy nasza sciane
        }
    }
    zamien(&tab[sciana], &tab[duzy]);//zamieniamy  pierwszy element przed  granica z naszym pivotem
    return sciana; //zwracamy miuejsce naszego pivota
}

void sortuj(int* tab, int maly, int duzy)
{
    if (maly < duzy)
    {
        int miejsce_pivota = podzial(tab, maly, duzy); //funckja zwracajaca nam w ktorym miejscu bedzie nasz pivot
        sortuj(tab, maly, miejsce_pivota - 1);  //sortowanie lewej czesci od malego do miejsce przed pivot'em
        sortuj(tab, miejsce_pivota + 1, duzy); //sorotwanie prawej czesci czyli od nastepnego po pivot'cie do duzego
    }

}
int main()
{
    cout << "Program do szybkiego sortowania!" << endl;
    int tab[N] = { 27, 10, 12, 20, 25, 13, 15, 22};
    cout <<"przed sortowaniem: "<<endl;
    wypisz(tab);
    cout<<"--------------------------"<<endl;
    cout <<"Po sortowaniu: " <<endl;
    sortuj(tab, 0, N - 1); //startujemy z argumentami 0 i N-1
    wypisz(tab);

    return 0;
}
