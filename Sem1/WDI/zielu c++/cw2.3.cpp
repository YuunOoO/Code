#include <iostream>
#include <cmath>

using namespace std;
float radiany(float kat)
{
    return ((kat*2*M_PI)/360);
}


int main()
{
  float a, b,  kat;

    cout << "podaj dlugosc przyprostokatnej a: " << endl;
    cin >>a;
    cout << "podaj kat: " <<endl;
    cin >> kat;
        float radian;
        radian = radiany(kat);
        b = (tan(radian)*a);


            cout<<"pole wynosi: " << ((a*b)/2);
    return 0;
}
