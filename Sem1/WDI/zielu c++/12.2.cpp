#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int mn, mx, n,dlugosc=-1,counter=0;
    bool koniec = true;
    cout << "Program, ktory dla wprowadzonych z klawiatury 3 liczb calkowitych mn, mx, n wygeneruje i zapisze w pliku tekstowym wyrazy.txt n wyrazow skladajacych sie z "<<endl;
    cout << "wybranych losowo liter alfabetu angielskiego. Kazdy wyraz powinien zostac zapisany w oddzielnej linii, ma zawierac losowa liczbe liter, najmniej mn, a najwiecej mx."<<endl;
    cout << " Kazdy wyraz musi zawierac co najmniej 1 litere, ale nie wiecej niz 30 liter."<<endl<<endl<<endl;
    cout << "Podaj mn, mx, n : ";
    cin >> mn >> mx >> n;
    if(mn<1 || mx>30) return 0; //jesli bledne parametry

    ofstream wyrazy("wyrazy.txt"); //zapis odczyt
    while(counter<n)        //dopoki licznik wyrazow nie przekroczy n
    {
        wyrazy << (char)(rand() % 25 + 97) ;            //losujemy litere

        if(dlugosc==0)                   //jesli koniec wyrazu
        {
            koniec = true;
            wyrazy << endl;
            counter++;
        }

        if(koniec)                       //okreslenie dlugosci wyrazu losujac
            dlugosc = rand() % (mx-mn) + mn, koniec = false;

        dlugosc--;
    }

    return 0;
}
