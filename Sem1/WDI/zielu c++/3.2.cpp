#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, p;
    cout << "Podaj dlugosci bokow trojkata: " << endl;
    cin>>a>>b>>c;

    p = (a + b + c)/2;
    if(a+b>c && a+c>b && b+c>a)
    {
        cout<<"Mozna zbudowac trojkat, a jego pole wynoski: "<<sqrt((p*(p-a)*(p-b)*(p-c)));
        return 0;
    }
    else cout<<"nie mozna zbudowac z tych bokow trojkata!";
    return 0;
}
