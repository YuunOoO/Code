#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;
const int N = 1000;

struct lista
{
    int w;
    lista *next;
};

void dodaj(int l, lista *&pierwszy)
{

    lista *kolejny = new lista;                 //tworzymy kontener i dodajemy wartosc
    kolejny ->w = l;
    kolejny ->next = 0;


    if(pierwszy->next==0)                       //pierwszy element listy
    {
        kolejny->next=0;
        pierwszy->next=kolejny;
        return;
    }

    lista *roboczy = pierwszy;                  //zmienna robocza
    lista *ogon = 0;                            // tworzymy ogon

    if(l>roboczy->w)                            //jesli dodajemy na poczatku
    {
        kolejny->next=pierwszy;
        pierwszy = kolejny;
        return;
    }

    while(l<roboczy->w && roboczy->next!=0)     //przewijamy sie przez liste
       ogon = roboczy, roboczy=roboczy->next;

    if(roboczy->next==0)                        //jesli dodajemy na samym koncu listy
    {
        roboczy->next=kolejny;
        return;

    }
    else                                        //dodajemy w srodku listy
    {
        kolejny->next=roboczy;
        ogon->next=kolejny;
        return;
    }

}

int main()
{
    srand( time( NULL ) );
    int n, liczba;
    cout << "Sortowanie tablic N losowych liczb <1,1000>" << endl;
    cin>>n;
    lista *p;
    for(int i=0; i<n; i++)
    {
        liczba = rand() % N;
        dodaj(liczba,p);
    }
    for(int i=0; i<n ; i++)
    {
        cout<<p->w, p=p->next;
        cout<<endl;
    }


    return 0;
}
