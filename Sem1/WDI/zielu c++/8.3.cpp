#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int potega(int i)
{
    if(i==0) return 1;
    int p=2;
    if(i==1) return p;
    for(int k=1;k<i;k++) p*=2;
    return p;
}

int main()
{
    srand( time( NULL ) );
    int tab[21];
    cout << "wypelnianie tablicy 21 elementowej kolejnymi potegami liczby 2 " << endl;
    for(int i=0 ; i<21; i++)
    {
        tab[i]=potega(i);
        cout << tab[i]<<endl;
    }

    return 0;
}
