#include <iostream>

using namespace std;

int main()
{
    unsigned int a,b,c,n,maks;
    cout << "Trojkat pitagorejski" << endl;
    cout << "podaj maksymalne liczbe : " << endl;
    cin >> maks;
    maks+=1;

    for(int m=1;m<maks;m++)
    {
       for(int n=1; n<maks; n++)
       {
            if(m<n) continue;
            a = m*m - n*n;
            b = 2*m*n;
            c = m*m + n*n;
            if(a>0 && b>0 && c>0 && a*a+b*b==c*c)    cout<<a<<"  "<<b<<"  "<<c<<endl;
       }
    }
    return 0;
}
