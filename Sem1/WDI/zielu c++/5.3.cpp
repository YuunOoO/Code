#include <iostream>

using namespace std;

int main()
{
    int w,k;
    cout << "Rysowanie prostokata z gwizdek!" << endl;
    cout << "podaj liczbe wierszy i kolumn :";
    cin>>w>>k;

    for(int i=0;i<w;i++)
    {
        for(int p=0;p<k;p++)
        {
            if(i==0 || i==(w-1) || p==0 || p==(k-1))
            cout <<"*";
            else cout <<" ";
        }
            cout<<endl;
    }

    return 0;
}
