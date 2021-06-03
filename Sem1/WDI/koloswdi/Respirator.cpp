#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool reanimacja(bool zycie,int tetno)
{
    tetno = rand() % 200 - 1;
    if(tetno==0) return true;
    cout << "Aktalne tetno : "<<tetno<<endl;
    return false;
}

int main()
{
    srand( time( NULL ) );
    cout << "Kod programu resporatora!" << endl;
    bool zycie = true;
    int tetno = 1, czas=0;

    do
    {
        czas++;
        if(reanimacja(zycie,tetno)) zycie=false;;
    }while(zycie);

    cout<<"Przezyles: " << czas<<"sekund pod respiratorem,  Gratulujemy! ";
    return 0;
}
