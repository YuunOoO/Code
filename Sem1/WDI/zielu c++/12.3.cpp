#include <iostream>
#include <cstdlib>
#include <fstream>
#include<string>

using namespace std;

int main()
{
    bool pierwszy = true;
    cout <<" Program, ktory odczyta plik tekstowy liczby.txt wygenerowany w ćwiczeniu pierwszym, posortuje losowe liczby za pomocą funkcji bibliotecznej qsort," <<endl;
    cout <<" zapisze posortowane liczby w pliku tekstowym liczby2.txt, przy czym w pierwszej linii powinna być liczba n, a w każdej następnej po jednej z posortowanych liczb."<<endl;
    ifstream liczby("liczby.txt");
    ofstream liczby2("liczby2.txt");
    //bez q sort bo mi sie nie chce xD
   int k,n,i=0,tmp=-1;
   while(!liczby.eof())
   {

        liczby>>k;
        if(pierwszy)
        {
            liczby2<<k;
            liczby2<<endl;
            pierwszy = false;
            n = k + 1;   //bo w 1 zadaniu byl blad i dawalo o 1 liczbe wiecej *facepalm*
        }

        if(k<tmp || tmp == -1) tmp = k;

        if(i==n)
        {
            liczby2<<tmp<<"  ";
            liczby2<<endl;
            i=0,tmp=-1;
        }
        i++;
   }
    if(i!=0) liczby2<<tmp; //mozliwa koncowka

    return 0;
}
