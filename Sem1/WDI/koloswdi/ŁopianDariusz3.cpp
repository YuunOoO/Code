#include <iostream>

using namespace std;

float wylicz(int i)
{
    float suma_tmp=5;
    for(int k=1; k<i;k++)
    {
        suma_tmp*=0.9;
    }
    return suma_tmp;
}

int main()
{
    cout << "Oblicz sume ciagu n wrazow!" << endl;
    cout << "Prosze podac n: ";
    int n;
    cin >>n;
    if(n<1)
    {
        cout<<"Nieprawidlowy parametr!";
        return 0;
    }

    //wzor an = 0,9 • an-1, dla a1=5
    float suma=0;

    for(int i=1;i<=n;i++)
        suma+=wylicz(i);

    cout<<"S"<<n<<" = " <<suma;
    return 0;
}
