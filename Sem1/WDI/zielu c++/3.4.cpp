#include <iostream>

using namespace std;

int main()
{
    char litera;
    cout << "Podaj duza litere w celu zamiany na mala: " << endl;
    cin >> litera;
    if((litera>='A')&&(litera<='Z'))
    {
        cout<<"Twoja litera to: "<<char(litera+32);
        return 0;
    }
    cout<<"Nieprawidlowy znak!";
    return 0;
}
