#include <iostream>

using namespace std;

int fib(int n)
{
    int a=1,b=0;
    for(int i=1;i<n;i++)
    {
        a+=b;
        b=a-b;
    }
    return a;
}

int main()
{
    int n;
    cout << "Oblicznanie n'tego wyrazu ciagu fib ale ITERACYJNIE" << endl;
    cout << "Podaj n: ";
    cin>>n;
    cout<<fib(n);

    return 0;
}
