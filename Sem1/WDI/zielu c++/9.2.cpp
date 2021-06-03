#include <iostream>

using namespace std;

int main()
{
    const int N = 10;
    cout << "Insert sort" << endl;
    cout << "posortujemy sobie dany ciag: ";
    int tab[N] = {4,7,3,1,5,23,12,32,11,6}; //generujemy sami bo mi sie nie chce inaczej xD

    for(int i=0; i<N; i++)
    {
        while(tab[i]>tab[i+1] && i>=0)
        {
            int tmp = tab[i+1];
            tab[i+1] = tab [i];
            tab[i] = tmp;
            i--;
        }
    }

    for(int i=0;i<N; i++) cout<<tab[i]<<" ";

    return 0;
}
