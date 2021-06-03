#include <iostream>

using namespace std;

int main()
{
    unsigned long long liczba;
    unsigned int i = 2;
    cout << "Program rozkladajacy na czynniki pierwsze" << endl;
    cout << "Podaj liczbe : "<<endl;
    cin >> liczba;
    cout << "Rozklad na czynniki wynosi: " ;

    while(liczba)
    {
        while(liczba%i==0)
        {
            cout<<i<<" ";
            liczba/=i;
        }
        i++;
    }
    return 0;
}
