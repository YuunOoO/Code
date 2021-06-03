#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int n,m,k,x=0;
    cout << "Program, który utworzy plik tekstowy liczby.txt, wygeneruje i zapisze w pliku n liczb losowych, z przedziału [—m, m].";
    cout << " W pierwszej linii pliku liczba n, a w kolejnych liniach po k wylosowanych liczb. Liczby ustawione w kolumnach.";
    cout << "Podaj n, m, k : ";
    cin >> n >> m >> k;
    ofstream liczby("liczby.txt");
    liczby<<k;
    liczby << endl;
    for(int i=0; i<n; i++)
    {
        liczby << ( rand() % (2*m) ) - m;
        liczby << "  ";
        x++;
        if(x>k)
        {
            x=0;
            liczby << endl;
        }
    }

    return 0;
}
