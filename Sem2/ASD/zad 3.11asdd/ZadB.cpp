#include <iostream>
using namespace std;

const int N = 10;
struct element  //struct na potrzeby zadania
{
    int counter;
    int idx;
    bool uzyty;
};

int main()
{
    cout << "Wyznacz krotnosc powtarzania sie poszczegolnych elementow w ciagu {a1, a2,...an}"<<endl;
    int ciag[N] = { 2,4,7,4,7,4,7,8,1,12 };
    element zliczaj[N]; // tablica robocza zeby zaoszczedzic ilosci operacji;
    for (int i = 0;i < N;i++)   //falsujemy na wszelki wypadek
        zliczaj[i].uzyty = false, zliczaj[i].counter = 0, zliczaj[i].idx = 0;

    for (int i = 0; i < N; i++)     //sortujemy [insert sort] -> N^2
    {
        while (ciag[i] > ciag[i + 1] && i >= 0)
        {
            int tmp = ciag[i + 1];
            ciag[i + 1] = ciag[i];
            ciag[i] = tmp;
            i--;
        }
    }
    int nr = 0;
    for (int i = 0; i < N;i++)      //skoro jest posortowane to wystarczy zliczyc liczbe wystapien
    {
        while (ciag[i] == ciag[i + 1] && i<N-1) //jesli sie powtarzaja
        {
            zliczaj[nr].counter++;  //liczymy ile razy
            i++;
            if (!zliczaj[nr].uzyty) //zeby nie robic tego za kazdym razem
            {
                zliczaj[nr].idx = ciag[i];
                zliczaj[nr].uzyty = true;
            }
        }
        if (zliczaj[nr].uzyty) nr++;    //zwiekszamy nr jesli byl juz uzyty
    }
    for (int i = 0; i < N;i++)
        if (zliczaj[i].uzyty)   //wypisujemy tylko uzyte nr 
            cout << "Liczba " << zliczaj[i].idx << " powtorzyla sie " << zliczaj[i].counter << " razy!"<<endl;
}
//zlozonosc w zaleznosci od uzytego sortowania [insert sort to N^2 ale mozna uzyc quicksorta Nlog(N)] + reszta algorytmu N -> N^2+N
