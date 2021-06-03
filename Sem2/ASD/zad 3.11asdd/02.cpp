#include <iostream>
using namespace std;
const int n = 7;
const int m = 9;

void wstaw(int (&tabA)[m+n],int tabB[m], int i)
{
    for (int k = 0; k < m;k++)       //transportujemy elementry tablicy robiac dziure na druga
        tabA[i + m + k] = tabA[i + k];

    for (int k=0;k <m;k++)    //dodajemy nasz ciag
    {
        tabA[i + k] = tabB[k];
    }
    return;
}

int main()
{
    bool wstawianie = false; //zmienna czy wstawiamy
    int tabA[n+m] = { 1,3,7,12,4,2,9 };
    int tabB[m] = { 5,7,21,3,53,12,3,5,7 };
    int c;
    cout << "Podaj liczbe C: ";
    cin >> c;
    for (int i = 0; i < n; i++) //przechodzenie po tablicy A
    {
        if (tabA[i] == c || i==n-1)  //jesli napotkamy wartosc rownej c -> aktywujemy wstawianie
            wstawianie = true;
        if (wstawianie) //jesli jest aktywowane wstawianie to wstawiamy!
        {
            i++;
            wstaw(tabA, tabB, i);
            break; //po co dalej to ciagnac skoro juz w tym miejscu jest wszystko zrobione -> przerywamy petle
        }
    }
    for (int i = 0;i <n+m;i++)       // wypisowanie testowe
        cout << tabA[i] << " ";

    return 0;
}
