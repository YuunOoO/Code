#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long liczba;
    unsigned long long suma = 0;
    cout << " suma cyfr liczby "<<endl;
    cout << "Podaj liczbe maksymalnie 18 cyforwej: " << endl;
    cin>>liczba;

    while(liczba!=0)
    {
        suma += liczba % 10;
        liczba/=10;
    }
    cout << suma;

    return 0;
}
