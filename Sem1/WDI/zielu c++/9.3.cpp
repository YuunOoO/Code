#include <iostream>

using namespace std;
const int N = 10;

void quicksort(int tab[], int lewy, int prawy)
{
    if(prawy<=lewy) return;
    int i = lewy - 1, j = prawy +1;
    int s = tab[(lewy+prawy)/2];
    while(1)
	{
		while(s>tab[++i]);
		while(s<tab[--j]);
		if( i <= j)
            swap(tab[i],tab[j]);   //funkcja swap zamienia wartosciami tab[i] z tab[j]
		else
			break;
	}

	if(j > lewy)
        quicksort(tab, lewy, j);
	if(i < prawy)
        quicksort(tab, i, prawy);

}

int main()
{

    int s = N / 2;
    cout << "Quicks sort" << endl;
    cout << "posortujemy sobie dany ciag: ";
    int tab[N] = {4,7,3,1,5,23,12,32,11,6}; //generujemy sami bo mi sie nie chce inaczej xD

    quicksort(tab,0,N-1);


    for(int i = 0; i<N; i++) cout<<tab[i]<< " ";
    return 0;
}
