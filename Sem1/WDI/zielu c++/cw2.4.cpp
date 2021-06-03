#include <iostream>
#include <cmath>

using namespace std;
float radiany(float kat)
{
    return ((kat*2*M_PI)/360);
}


int main()
{
  float a, b,  alfa, beta, pole;

    cout << "podaj dlugosc a: " << endl;
    cin >>a;
    cout << "podaj kat alfa, beta: " <<endl;
    cin >> alfa>>beta;
        float r1,r2;
        r1 = radiany(alfa);
        r2 = radiany(beta);
        pole = ((a*((tan(r1)*tan(r2))/(tan(r1)+tan(r2))))*a)/2;

            cout<<"pole wynosi: " << pole;
    return 0;
}
