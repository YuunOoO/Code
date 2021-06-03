#include <iostream>

using namespace std;

int main()
{
    cout << "Program do obliczania kwadratow liczb od -100 do 100!" << endl;
    int n=100;

    for(int i=-n; i<=n; i++)
    {
        cout<<i<<"^2 ="<<i*i<<endl;
    }
    return 0;
}
