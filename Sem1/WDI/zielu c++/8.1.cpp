#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand( time( NULL ) );
    int tab[6]={0,0,0,0,0,0};
    const int N=1000;
    int wylosowana_liczba;
    cout << "Witamy w algorytmie losowania 1000x i zliczania ilosci oczek w kostce 6 oczkowej" << endl;

    for(int i=0; i<1000; i++)
    {
       wylosowana_liczba =(rand() % 6 ) + 1;
       if(wylosowana_liczba == 1) tab[0]++;
       else if(wylosowana_liczba == 2) tab[1]++;
       else if(wylosowana_liczba == 3) tab[2]++;
       else if(wylosowana_liczba == 4) tab[3]++;
       else if(wylosowana_liczba == 5) tab[4]++;
       else if(wylosowana_liczba == 6) tab[5]++;
    }
    cout << "wylosowano : " << tab[0]<< " - 1 oczek " << tab[1]<< " - 2 oczek " <<tab[2]<< " - 3 oczek " ;
    cout <<tab[3]<< " - 4 oczek " << tab[4]<< " - 5 oczek " <<tab[5]<< " - 6 oczek " ;
    return 0;
}
