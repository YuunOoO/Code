#include <iostream>
#include <cmath>

using namespace std;

bool sprawdz(int x)
{
    int m = sqrt(x);            // lub pow(x,0.5)
    if (m * m == x) return true;
    return false;


    //inny sposob
    //for(int i=1; i<x/2; i++)
    //{
    //if(i*i==x) return true;
    //}
}

int main()
{
    cout << "Program do sprawdzania ilosci kwadratow liczb!" << endl;
    cout << "Prosze podac ilosc liczb: ";
    int n,counter=0;
    cin >>n;
    int tab[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Podaj "<<i+1<<" liczbe: ";
        cin>>tab[i];
        if(sprawdz(tab[i])) counter++;
    }
    cout << "Wystepuje tutaj " <<counter<<" kwadratow liczb";
    return 0;
}
