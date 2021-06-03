#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    const int N = 1000;
    cout << "Blizniacze(1000) liczby przy uzucia algorytmu sita " << endl;

    bool tab[N];
    int k;
    int t[N];

    for(int i=0; i<N; i++) t[i]=0;          //zerujemy i true'jemy tablice
    for(int i=3; i<1000;i++) tab[i] = true;
    tab[0]=tab[1]=tab[2]=false;

    for(int i=2; i<1000; i++)           //sito
        for(int j=i+1; j<=1000; j++)
            if(j%i==0) tab[j] = false;



    for(int i=0,k=0; i<1000;i++) if(tab[i]) t[k]=i,k++;  //przypisujemy
    for(int i=0; i<N-1; i++)                                //wypisujemy
        if (t[i+2]!=0) cout<<"("<<t[i]<<","<<t[i+1]<<") , ";
            else
            {
                cout<<"("<<t[i]<<","<<t[i+1]<<")";              //ostatni przypadek zeby nie bylo na konczu " , "
                break;
            }

    return 0;
}
