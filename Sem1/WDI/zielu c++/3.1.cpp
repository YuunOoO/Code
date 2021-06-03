#include <iostream>

using namespace std;

int main()
{
    int liczba;
    cout << " Program podzielnosci liczby przez 3 / 2"
    cout << "Podaj liczbe: " << endl;
    cin>>liczba;
    if(liczba==0) return 0;

    if(liczba%3==0)
    {
        if(liczba%2==0)
        {
            cout<<"jest podzielna przez 3 i 2 ,   (6)"<<endl;
            return 0;
        }
        cout<<"jest podzielna przez 3 ,   (3)"<<endl;
        return 0;
    }
    if(liczba%2==0)
    {
        cout<<"Jest podzielna przez 2 ,  (2)"<<endl;
        return 0;
    }
    cout<<"nie jest podzielna ani przez 3 ani przez 2 ,  (1)"<<endl;
    return 0;
}
