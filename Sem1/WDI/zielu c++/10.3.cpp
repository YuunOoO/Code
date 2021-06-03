#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int rzut(int a, int b)
{
    return a+b;
}

int main()
{
    srand(time(NULL));
    int n,suma_p,suma_c=0; //suma_p (suma poszczegolnych rzutow) , suma_c(suma calkowita)
    int tab[11]={0,0,0,0,0,0,0,0,0,0,0};                                  // (1+1,6+6) -> (2,12) -> 11 mozliwosci;
    cout << "Symulowanie n rzutow dwoma szesciennymi kostkami" << endl;
    cout << "Podaj n: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
       suma_p = rzut(rand()%6+1 , rand()%6+1);      //losujemy

       for(int l=0; l<11; l++)         //dodajemy jesli wystepuje taka suma
       if(suma_p==l+2) tab[l]++;

       suma_c += suma_p;
    }
    for(int i=0;i<11;i++)
        cout<<"Sume "<<i+2<<" wylosowano : "<<tab[i]<<" razy" <<endl;

    cout << "Calkowita suma wylosowanych oczek to : " <<suma_c;
    return 0;
}
