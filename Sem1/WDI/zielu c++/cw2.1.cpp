#include <iostream>
#include <cmath>

using namespace std;

float przekatna(float a)
{
    return a*sqrt(2);
}
int main()
{
float a;
    cout << "Podaj dlugosc boku a: " << endl;
    cin >> a;

    cout<<"przekatna wynosi: "<< przekatna(a) <<endl;

    return 0;
}
