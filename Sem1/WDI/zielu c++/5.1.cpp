#include <iostream>

using namespace std;

int main()
{
    int suma=0;
    int liczba=0;
    cout << "Liczby Armnstronga, wszystkie liczby 3 cyfrowe" << endl;

    for(int i=0; i<10; i++)
    {
    suma=(i*i*i);
    liczba=i;
        for(int k=0;k<10;k++)
        {
            suma+=(k*k*k);
            liczba=liczba*10+k;
            for(int p=0;p<10;p++)
            {
                suma+=(p*p*p);
                liczba=liczba*10+p;
                if(suma==liczba) cout <<liczba<<"  ";
                suma-=(p*p*p);
                liczba/=10;
            }
            suma-=(k*k*k);
            liczba/=10;
        }
    }
    return 0;
}
