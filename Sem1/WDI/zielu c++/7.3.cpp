#include <iostream>
#include <cmath>

using namespace std;

float fib(int n)
{
    float p = sqrt(5);
    float x1=((1+p)/2);
    float x2 = ((1-p)/2);



    return (1/p)*(pow(x1,n)-pow(x2,n));
}

int main()
{
    int n;
    cout << "Oblicznanie n'tego wyrazu ciagu fib ale ZA POMOCA WZORU" << endl;
    cout << "Podaj n: ";
    cin>>n;
    cout<<fib(n);

    return 0;
}
