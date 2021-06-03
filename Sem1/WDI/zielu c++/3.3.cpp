#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, delta;
    cout << "Podaj wspolczynniki funkcji kwadratowej a, b , c : " << endl;
    cin>>a>>b>>c;
        if(a==0)
        {
        if(b==0)
        {
            if(c==0)
            {
                cout<<"nieskoczenie wiele miejsc zerowych"<<endl;
                return 0;
            }
                cout<<"Brak miejsc zerowych"<<endl;
                return 0;
        }
    cout<<"Miejsce zerowe wynosi X0 = " <<((-c)/b)<<endl;
    return 0;
        }

    delta = b*b - (4*a*c);
        if(delta >= 0)
        {
            if(delta==0)
            {
                cout<<"Jedno miejsce zerowe X0 = " <<(-b/(2*a));
                return 0;
            }
                cout<<"dwa miejsca zerowem, x1 = "<<((-b)+(sqrt(delta)))/(2*a) << "  ,  x2 = " << ((-b)- (sqrt(delta)))/(2*a)<<endl;
                return 0;
        }
    cout<<"Brak miejsc zerowych"<<endl;

    return 0;
}
