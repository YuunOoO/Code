#include <iostream>

using namespace std;

int main()
{
    unsigned long long a,b;
    cout << "Najmniejsza wspolna wielokrotnosc!" << endl;
    cout << "Podaj 2 liczby: " <<endl;
    cin >> a >> b;

    if(a==b)            // pierwszy przypadek
    {
         cout <<" NWD wynosi : "<<a;
         return 0;
    }

    do                 // 2 przypadek
    {
        if (a>b) a%=b;
        else b%=a;
    }
    while(a&&b);

    cout <<" NWD wynosi : "<<(a+b);
    return 0;
}
