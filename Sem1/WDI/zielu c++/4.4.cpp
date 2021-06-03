#include <iostream>

using namespace std;

unsigned long int suma_cyfr(unsigned long int &l)
{
    unsigned long int suma = 0;
    while(l)
    {
        suma += l%10;
        l/=10;
    }
    l = suma;
}

int main()
{
    unsigned long int liczba;
    cout << "Jednocyfrowa suma cyfr!" << endl;
    cout << "Podaj liczbe : " <<endl;
    cin >> liczba;

    while(liczba>10)
    {
        suma_cyfr(liczba);
    }
    cout << liczba;
    return 0;
}
