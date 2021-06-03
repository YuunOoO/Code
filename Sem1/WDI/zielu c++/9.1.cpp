#include <iostream>

using namespace std;

int main()
{
    int x = 1, j=0;
    const int N = 10;
    cout << "Shaker sort" << endl;
    cout << "posortujemy sobie dany ciag: ";
    int tab[N] = {4,7,3,1,5,23,12,32,11,6}; //generujemy sami bo mi sie nie chce inaczej xD
    for (int i=0;i<10;i++) cout << tab[i]<<" ";

    for(int i=0;i<N;i++)    //sortowanie
        {
            j=i;
            for(;j<N-x;j++)
                if(tab[j]<tab[j+1])
                {
                    int tmp = tab[j+1]; //podmiana
                    tab[j+1] = tab[j];
                    tab[j] = tmp;
                }
            for(j; j>x-1; j--)
                if(tab[j]>tab[j-1])
                {
                    int tmp = tab[j-1];
                    tab[j-1] = tab[j];
                    tab[j]=tmp;
                }
            x++;
        }

    cout << "Posortowant ciag : " ;
    for (int i=0;i<10;i++) cout << tab[i]<<" ";

    return 0;
}
