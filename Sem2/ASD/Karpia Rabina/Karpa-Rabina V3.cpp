#include <iostream>
#include <conio.h>
using namespace std;

void find(string tekst, long long sum, int d, int n, int m, int* place) //funkcja znajdujaca prawdopodobne wystapienie wzorca 
{
    long long sum_tmp, znalezionych;
    znalezionych = 0;
    for (int i = 0;i < m - n;i++)//przesuwamy sie w prawo po tekscie od 0 do dlugosc tekstu - dlugosc frazy (zeby nie wyjsc poza zakres)
    {
        sum_tmp = 0;//zerujemy nasze zmienne
        int p = i;
        for (int k = i;k < p + n;k++)   //sprawdzamy od danego miejsca do dlugosci frazy 
        {       
            sum_tmp = sum_tmp * d + (int)tekst[k]; //obliczamy koszt
        }
        if (sum_tmp == sum) //jesli koszty sa te same to jest prawdopodobienstwo ze znalezlismy to czego szukamy
        {
            place[znalezionych] = i; //zapisujemy miejsce 
            znalezionych++; //iterujemy
        }
    }
}
int main()
{
    string tekst, tmp, fraza;
    cout << "Witamy w programie wyszukiwania wzorcu! " << endl;
    cout << "Wpsiz tekst glowny!(koniec wczytywania poleceniem 'stop')[max 255 znakow] : ";
    cin >> tmp;
    while (tmp != "stop")   //sklejamy tekst glowny
    {
        tekst += tmp;
        tekst += " ";
        cin >> tmp;
    }
    cout << "Teraz podaj szukana fraze(koniec wczytywania poleceniem 'stop'): ";
    cin >> tmp;
    while (tmp != "stop")//sklejamy tekst frazy
    {
        fraza += tmp;
        fraza += " ";
        cin >> tmp;
    }
    cout << "Tekst glowny to: " << tekst << endl;
    cout << "Szukana fraza to: " << fraza << endl;
    int m = tekst.length() - 1; //dlugosc tekstu
    int n = fraza.length() - 1; //dlugosc frazy
    if (n > m) //obsluga bledu 
    { 
        cout << "Fraza nie moze byc dluzsza od tekstu!";
        return 0;
    }
    int counter = 0;
    char omega[255];
    for (int i = 0; i < m;i++)  //wyliczamy ile mamy roznych liter(moc zbioru omega)
    {
        bool dodaj = true;
        for (int k = 0;k < counter;k++)
            if (omega[k] == tekst[i])//jesli litera sie powtworzyla to nie dodajemy
                dodaj = false;
        if (dodaj)  //jesli sie nie powtorzyla to znalezlismy nowy znak ktory wczesniej nie wystapil
        {
            omega[counter] = tekst[i];
            counter++;
        }
    }
    for (int i = 0;i < n;i++) // obsluga bledu (Fraza zawiera znaki ktorych nie ma w tekscie glownym)
    {
        for (int k = 0;k < counter;k++)
        {
            if (fraza[i] == omega[k])break;//jesli znak sie nzajudej to wychodzimy z petli
            if (k == counter - 1)//jesli nie to na ostatnim takcie petli skonczymy program
            {
                cout << "Fraza zawiera znaki ktore nie wystepuja w glownym tekscie!";
                    return 0;
            }
        }
    }

    int d = counter;
    long long sum;
    sum = 0;
    for (int i = 0;i < n;i++)//obliczamy nasz koszt dla frazy
    {
        sum = sum * d + (int)fraza[i];
    }
    int place[255];
    for (int i = 0;i < 255;i++)//zerujemy tablice
        place[i] = 0;
    find(tekst, sum, d, n, m, place);   //funkcja wyszukujace
    bool znaleziono = false;
    for (int i = 0;i < 255;i++)
    {
        if (place[i] != 0) //jesli cos znalezlismy to sprawdzamy
        {
            string tmp;
            int k = place[i];
            for (k;k < place[i] + n;k++)
            {
                tmp += tekst[k]; //tworzymy nasz tekst tymczasowy
            }
            if (tmp == fraza || tmp + " " == fraza)//jesli faktyczna fraza sie zgadza to wypisujemy
            {
                cout << "Znaleziono fraze '" << tmp << "' ktora wystapila po znaku nr: " << place[i] << endl;
                znaleziono = true;
            }
        }
    }
    if (!znaleziono)cout << "Nie znaleziono podanej frazy! :("; //jesli nie znalezlismy frazy w tekscie
}
