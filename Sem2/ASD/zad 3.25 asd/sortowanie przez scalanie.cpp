#include <iostream>
using namespace std;

const int N = 8;

void wypisz(int* tab)
{
    for (int i = 0;i < N;i++)
        cout << tab[i] << endl;
}

void scal(int* tab, int l, int srodek, int p) // zmienne takie same jak przy sortowaniu zeby sie nie mylilo
{
    int rozmiar_l = srodek - l + 1; //rozmiar lewej tablicy to  srodek minus lewo (ale element srodkowy zaliczamy do lewej strony wiec +1
    int rozmiar_p = p - srodek; // jak od idx z prawej odejmiemy srodek to otrzymamy rozmiar prawej strony

    int* tab_lewa = new int[rozmiar_l]; //tablice pomocnicze lewa
    int* tab_prawa = new int[rozmiar_p];  // i prawa

    //teraz wypelniamy nasze tablice pomocnicze 
    for (int i = 0;i < rozmiar_l;i++)
        tab_lewa[i] = tab[l + i];       //tablica lewa jest od 0 do rozmiaru a tablica glowna interesuje nas w przedziala od lewej strony do srodka(a ze mamy rozmiar to nie przekorczymy zakresu)

    for (int i = 0;i < rozmiar_p;i++) //to samo dla prawej
        tab_prawa[i] = tab[srodek + i + 1];  //tyle ze tu pomijamy jedna tablice

    int idx_l = 0;  //index lewy
    int idx_p = 0;  //index prawy
    int aktualny;   //aktualny
    
    for (aktualny = l; idx_l < rozmiar_l && idx_p < rozmiar_p;aktualny++)   //jesli zadny indeks nie przekroczy swojego rozmiaru
    {
        if (tab_lewa[idx_l] <= tab_prawa[idx_p])    //i lewy element tablicy jest mniejszy od prawej
            tab[aktualny] = tab_lewa[idx_l++];  //nadpisz glowna tablice i zwieksz idx lewego
        else
            tab[aktualny] = tab_prawa[idx_p++]; // w przeciwnym wypadku to samo dla prawego
   }

    while (idx_l < rozmiar_l)       //jesli cos zostalo jeszcze w lewej tablicy
        tab[aktualny] = tab_lewa[idx_l++];  // to przepisz
    while (idx_p < rozmiar_p)   //to samo dla prawej
        tab[aktualny] = tab_prawa[idx_p++];
   
    delete[] tab_lewa;  //pozbywamy sie zbednych tablic
    delete[] tab_prawa;

}

void sortowanie(int* tab, int l, int p) // l - lewo , p -prawo
{
    if (p > l) // jesli idx prawego wiekszy niz lewy 
    {
        int srodek = (p + l) / 2;   //wyznaczamy nasz srodek
        sortowanie(tab, l, srodek); //lewa strona [dzielenie]
        sortowanie(tab, srodek + 1, p); //prawa strona  [dzielenie]
        scal(tab, l, srodek, p); // scalamy 
    }

}


int main()
{
    cout << "Sortowanie przez scalanie!";
    int tab[N] = { 27, 10, 12, 20, 25, 13, 15, 22};
    cout << "Przed sortowaniem:" << endl;
    wypisz(tab);
    cout << "-----------------" << endl;
    cout << "Po sortowaniu: " << endl;
    sortowanie(tab, 0, N-1);
    wypisz(tab);

}
