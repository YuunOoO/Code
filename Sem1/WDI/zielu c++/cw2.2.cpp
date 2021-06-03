#include <iostream>
#include <cmath>

using namespace std;

float przekatnaprost(float  a,float b)
{


     return sqrt((a*a)+(b*b));
}

int main()
{
float a,b;
    cout << "Podaj dlugosci bokow  a,b : " << endl;
    cin >> a >> b ;

    cout<<"przekatna wynosi: "<< przekatnaprost(a,b) <<endl;

    return 0;
}
