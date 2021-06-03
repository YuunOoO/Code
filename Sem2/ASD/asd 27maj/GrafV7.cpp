#include <iostream>
#include <cstdlib>
#include <fstream>
#include<string>
#include<time.h>
#include <ctime>
#include <windows.h>

using namespace std;

struct dodatek      //struktura dodatkowa
{
    int waga;   //waga drogi
    int skad;   //skad
    int cel;    //do kad 
    //czyli po prostu takie z A do B z kosztem [czyli krawedz dla nas]
};

int szatkuj(string linia, int* pomocnicza, int roz) //funkcja do poszatkowania naszych lini z getline'a
{
    string wyraz;
    wyraz.clear();
    int k = 0;
    for (int i = 2;i < roz + 1;i++) //zaczynamy od 3 znaku bo wtedy zaczynajas sie dane
    {
        if (linia[i] != ' ')    //jesli nie ma spacji
        {
            wyraz += linia[i];  //to dodajemy do naszego wyrazu kolejne znaki
        }
        else     //jesli jest spacja to znaczy ze jest koniec liczby
        {
            pomocnicza[k] = stoi(wyraz);//zamieniamy stringa na inta 
            k++;    // licznik ++ bo mamy o jedna liczbe wiecej
            wyraz.clear();//czyscimy nasz wyraz
        }
    }
    return k;   //zwracamy ile bylo poszatkowanych liczb
}

void visit(int* tab[], int* v, int i, int n, dodatek* q, int skad)  //funkcja do odwiedzania w glab (rekurencja)
{
    v[i] = 1;//oznaczamy ze bylismy w wierzcholku
    int min, idx;
    min = 1000;//to jest takie nasze infinity (przyjmuje ze waga nie przekroczy 1000 
    for (int t = 0;t < n;t++)
        if (tab[i][t] != 0)
            if (tab[i][t] < min || min == 1000)//jesli znajdziemy tansza 
                min = tab[i][t], idx = t;   //to zamieniamy
    if (min != 1000)//jesli min juz byl zmieniony 
    {
        q[i].waga = min;    //przypisujemy wage i inne rzeczy do naszej struktury
        q[i].skad = skad + 1;
        q[i].cel = idx + 1;
    }


    for (int k = 0;k < n;k++)
        if (tab[i][k] != 0)//jesli w macierzy sasiedztwa cos jest
            if (v[k] == 0)//jesli nieodwiedzony
                visit(tab, v, k, n, q, idx);    //wywolujemy dalej w glab nasza funkcje
}

void przeszukaj(int* tab[], int* v, int n, dodatek* q)//przeszukiwanie grafu dfs
{
    for (int k = 0;k < n;k++)
        if (tab[0][k] != 0)//oznacamy nasz pierwszy wierzcholek
            q[k].skad = 1, q[k].waga = tab[0][k], q[k].cel = k + 1;
    for (int i = 0;i < n;i++)
        if (v[i] == 0)//jesli nieodwidzony 
            visit(tab, v, i, n, q, i);//to odwiedzamy xd czyli wywolamy z 0,0 na starcie (to bedzie nasz wierzcholek startowy)
}
void znajdz(int* way[], dodatek* q, int k, int* koszt)  //funkcja do znajdywania najdluzszej sciezki za pomoca juz wczesniej wyznaczonych najoptymalniejszych krawedzi
{
    int* way_tmp = new int[k+1];    //tablica z droga pomocnicza
    int leng, cost, tmp, counter, l_max;
    counter = l_max = 0;
    bool znaleziono;
    bool* vis = new bool[k];// tablica z odwiedzinami
    for (int z = 0;z < k+1;z++) way_tmp[z] = 0; //zerujemy

    for (int t = 0;t < k;t++)
    {
        leng = cost = 0; //zerujemy koszt
        tmp = t;//zapamietujemy gdzie sie zatrzymalismy

        for (int p = 0;p < k;p++) vis[p] = false, way_tmp[p] = 0;//falszujemy,zerujemy tablice za kazdym podejsciem

        znaleziono = false;//zmienna pomocnicza 
                while (znaleziono == false)//jesli mozna jeszcze jakas droge sprawdzic to bedziemy w petli
                {
                 way_tmp[leng] = q[t].skad; //zapisujemy droge tymczasowa
                 leng++;//zwiekszamy dlugosc
                 cost += q[t].waga;//dodajemy koszt
                 vis[t] = true;//podkreslamy odwiedzenie
                 bool help = false;
                     for (int c = 0;c < k;c++)
                     {
                         if (vis[c] == false)//jesli jeszcze nie uzywalismy tej krawedzi
                         {
                             if (q[t].cel == q[c].skad) //a nasz koniec jednej krawedzi jest rowny poczatkowi drugiej krawedzi
                             {
                                 t = c;//to przechodzimy do tej krawedzi
                                 help = true;
                                 break;//wychodzimy z tej podpetli
                             }
                         }
                        
                     }
                     if (help == false)znaleziono = true;//jesli nie znalezlismy takiej krawedzi to nic nie wyymslimy trzeba stad wyjsc
                 }
                if (way_tmp[leng-1] == way_tmp[0])way_tmp[leng] = q[t].cel; // naprawia mozliwy blad ostatniej krawedzi
                
                
                 

        if (leng >= l_max)//jesli dlugosc tymczasowej drogi jest wieksza lub rowna maksymalnej
       {
            if (leng == l_max) counter++; //jesli jest rowna to chcemy obie te drogi wypisac
            l_max = leng;//podmieniamy
            for (int z = 0;z <= leng;z++)
                way[counter][z] = way_tmp[z];//zapsujemy nasza droge
            koszt[counter] = cost;//oraz koszt 
       }

        t = tmp;//wracamy do poprzedniego t 

    }
}

int main()
{
    time_t start, stop; //zmienne do czasowki 

    ifstream dane("dane.txt");//wczytujemy z dane 
    string linia;
    int k;
    getline(dane, linia);//bedziemy pobierac po lini
    k = stoi(linia);//zamieniamy pierwsza linie na liczbe ( jest to ilosc wierzcholkow)
    int* v = new int[k];
    int** tab = new int* [k];	//inicjalizujemy tablice tablic
    for (int i = 0;i < k;i++)	//generujemy nasze podtablicle
        tab[i] = new int[k], v[i] = 0;//zerujemy

    for (int i = 0;i < k;i++)
        for (int x = 0;x < k;x++)
            tab[i][x] = 0;	//zerujemy nasze wszystkie tablice

    int i = 0;
    while (!dane.eof())// jesli nie ma konca pliku
    {

        getline(dane, linia, '\n');//pobieramy linie
        int roz = linia.length();//sprawdzamy jego dlugosc
        int* pomocnicza = new int[roz];//tablica pomocnicza
        linia += " ";//dodajemy na koncu spacje zeby nie wyjsc poza zakres
        int ile = szatkuj(linia, pomocnicza, roz);//szatkujemy nasza linie
        for (int u = 0; u < ile - 1;u += 2)//wrzucamy dane do macierzy sasiedztwa
        {
            int j, var;
            j = pomocnicza[u];
            var = pomocnicza[u + 1];
            tab[j - 1][i] = var;
        }
        i++;
    }
    start = clock();//startujemy zegar

    for (int i = 0;i < k;i++)   //wypisujemy macierz sasiedztwa
    {
        for (int x = 0; x < k;x++)
            cout << tab[i][x];
        cout << endl;
    }

    dodatek* q = new dodatek[k];//alokujemy pamiec dla naszej struktury tablicowej
    for (int t = 0;t < k;t++) q[t].waga = 1000, q[t].skad = 0, q[t].cel = 0; //zerujemy nasza strukture (i infinity na wage)
    przeszukaj(tab, v, k, q);//uruchamiamy szukanie
    cout << "Graf ma " << k << " wierzcholkow!" << endl;
    bool spojnosc = true;
    for (int t = 0; t < k;t++)
    {
        if (v[t] != 0) cout << "wierzcholek " << t + 1 << " byl owiedzony!" << endl;//jesli wierzcholek byl odwiedzony to ma wartosc 1 
        else
            spojnosc = false;//jesli wierzcholek nie byl odwiedzony to znaczy ze graf nie bylby spojny
    }
    if (spojnosc) cout << "Graf jest spojny!" << endl;
    else  cout << "Graf nie jest spojny ): " << endl;

    bool skierowany = false;
    for (int t = 0;t < k;t++)
        for (int u = 0;u < k;u++)
            if ((tab[t][u] != 0 && tab[u][t] == 0) || (tab[u][t] != 0 && tab[t][u] == 0))//jesli istnieje droga w jedna strone a w druga jej nie ma to znaczy ze graj jest nieskierowany
                skierowany = true;
    if (skierowany) cout << "Graf skierowany" << endl;
    else cout << "Graf nieskierowany" << endl;


    for (int i = 0;i < k;i++)	//zeruj
        v[i] = 0;
    cout << "Najlepsze trasy to: " << endl;
    for (int t = 0;t < k;t++) cout << "Waga : " << q[t].waga << " z " << q[t].skad << " do  " << q[t].cel << endl;//wypisujemy najlepsze krawedzie
    int** way = new int* [k];
    int* koszt = new int[k];
    for (int t = 0;t < k;t++)way[t] = new int[k+1];

    for (int t = 0;t < k;t++)
        for (int u = 0;u < k;u++)
            way[t][u] = 0;
    znajdz(way, q, k, koszt);//algorytm znajdywania najdluzszych drog
    int drog = 0;
    cout << "Najdluzsze drogi:" << endl;
    for (int t = 0;t < k;t++)
    {
        if (way[t][0] != 0)//jesli nie ma samych zer w tablicy
        {
            cout << "Trasa nr: " << t + 1 << "  " << endl;
            cout << "Kolejnosc przechodzenia po wierzcholkach: ";
            for (int u = 0;u < k+1;u++)
            {
                if (way[t][u] != 0)cout << way[t][u] << " , ";
            }
            cout << "Koszt drogi: " << koszt[t] << endl;
            drog++;
            cout << endl;
        }
    }
    cout << "Znaleziono " << drog << " najdluzszych drog" << endl;

    stop = clock(); //koniec czasu

    cout << "Czas trwania algorytmu: " << stop - start;//wypisujemy czas trwania algo
}
