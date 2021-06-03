#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int n,tmp;
    srand( time( NULL ) );
    cout << "Program,ktory losuje n cyfr, a nastepnie wypisuje ilosc powtorzen." << endl;
    cout << "Podaj n: ";
    cin >> n;
    int tab[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<10; i++)
    {
        for(int k=0; k<n; k++)
        {
            tmp = rand()%10;
            if(i==tmp) tab[i]++;
        }
    }
    for(int i=0;i<10;i++) cout<<"Wylosowano "<<tab[i]<<" ,  "<<i+1<<"'ek "<<endl;
    return 0;
}
