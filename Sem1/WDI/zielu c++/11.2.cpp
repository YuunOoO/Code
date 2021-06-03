#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string wyraz;
    int klucz, klucz2, dlugosc;
    cout << "Algorytm cezara" << endl;
    cout << "Podaj wyraz do zaszyfrowania(male litery wylacznie):"<<endl;
    cin >> wyraz;
    cout << "Podaj klucz do szyfrowania(liczba): ";
    cin >> klucz;
    dlugosc = wyraz.length();
    for(int i=0; i<dlugosc; i++)
    {
        wyraz[i] = (int)wyraz[i]+klucz;
    }
    cout<<"Zaszyfrowano wiadmosc! Podaj klucz do deszyfracji: "<<endl;
    cin >> klucz2;
    for(int i=0; i<dlugosc; i++)
    {
        wyraz[i] = (int)wyraz[i]-klucz2;
    }
    cout<<wyraz;
    return 0;
}
