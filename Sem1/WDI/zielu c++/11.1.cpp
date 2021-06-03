#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

const int N = 204; //zmienne widoczne dla wszystkich (N+N + mozliwu przerzut 9*9= 81 -> +2  + znak konca i poczatka dla nas +1 = 204)
int  tab[10][N];  //tablica na liczby calkowite   [ ktora liczba ] [ jej cyfra na odpowienim miejscu ]
char okreslznak(string liczba)     // dla dalszego zastosowania!!
{
if(liczba[0]=='-')
       return '-';
    else
        return '+';
}
void rozloz(string liczba , int i , int (&tab)[10][N])
{
    int x=103; //srodek tablicy tak jakby dla calkowitych  / x x liczby , liczby /     (1)(2)(100), (100)(1)
    int p=0;
    int dodatek=0; //szczegolny przypadek
    int m = liczba.size() -2;
    while(liczba[p]!=',' && p<m)   //przewijamy do przecinka
        p++;
    if(liczba[p]!=',') dodatek = 1; //szczegolny przypadek

    for(int k=0; k<N-1; k++)
        if(liczba[p+k+1]!='/' && liczba[p-k-1]!='-' && liczba[p-k-1]!='+')              //dodajmy liczby po przecinku do tablicy
            tab[i][k+x+1] = ((int)liczba[p+k+1]-48);
        else break;

     for(int k=0; k<N-1; k++)
        if(liczba[p-k-1+dodatek]!='/')                                                     //dodajemy calkowite liczby do tablicy
           tab[i][x-k] = ((int)liczba[p-k-1+dodatek] - 48);
        else break;
    return;
}
void dodaj(int (&tab)[10][N], int i, string (&znak)[10])
{
    int tmp=1;
    if((znak[i] =="+" && znak[i-1]=="+") || (znak[i] == "-" && znak[i-1] == "-"))  //dla dalszego zastosowania
    {
        for(int k=N-1; k>=0; k--)
        {
            if(tab[i][k]>-1 && tab[i-1][k]>-1)          //dodawanie w srodku
            {
                tab[i][k]+=tab[i-1][k];
                if(tab[i][k]>=10)               //narzut
                {
                    tab[i][k]-=10;
                    tab[i][k-1]+=1;
                    if(tab[i][k-1]==0)          //szczegolony przypadek narzutu
                        tab[i][k-1]+=1;
                }
            }
            else
                if(tab[i][k]==-1 && tab[i-1][k]>-1)     //dodawanie poza
                    tab[i][k]=tab[i-1][k];
        }
    }
    if(tmp>0) znak[i]="+"; //dalsze zastosowanie
    else znak[i]="-";
    cout<<znak[i];
    for(int u=0; u <N; u++)                   //wyswietlanie wyniku
    {
        if(tab[i][u]!=-1)
            cout<<tab[i][u];
        if(u==103) cout<<",";
    }
    cout<<endl;
return;
}
int main()
{
    int n;
    cout << "Program do dodawnia do 10 liczb stalopozycyjnych ze znakiem, kazda do 100 cyfr przed i po przecinku!(tylko dodatnie :C )" << endl;
    cout << "ile liczb?: ";
    cin>> n;
    string liczba;
    string znak[10] ;     //tablica na +/- kazdej liczby

    for(int k=0;k<n;k++)
        for(int i=0;i<N;i++)            //minusujemy nasze tablice zeby odroznic pozniej puste tablice
            tab[k][i]=-1;

    for(int i=0; i<n; i++)
    {
        cout<<"Podaj liczbe dodatnia: " ;
        cin>>liczba;
        znak[i] = okreslznak(liczba); //dla daleszego zastosowania
        liczba = '/'+ liczba +'/' ; //dodajemy na koniec zeby latwiej bylo znalezc poczatek i koniec
        rozloz(liczba,i,tab);
        if(i>0)
            dodaj(tab,i,znak);
        cout<<endl;

    }
    return 0;
}
