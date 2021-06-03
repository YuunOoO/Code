#include <iostream>
using namespace std;

//Rozwiąż poniższy problem za pomocą algorytmu zachłannego. Rozważ dwa
//przypadki:
//1. Stała liczba kontenerów i zmienna ładowność statku
//2. Stała ładowność statku i zmienna liczba kontenerów
//W porcie stoi statek, którego ładowność wynosi X ton gotowy do załadunku.
//Statek można załadować różnymi kontenerami, których liczba jest równa K.
//Kontener i - ty posiada swój ciężar C(i) oraz wartość W(i).Oblicz optymalny
//załadunek kontenerów na statek, tzn.określ, które kontenery zostaną
//załadowane oraz w jaki sposób, aby wartość ładunku była maksymalna.

const int k = 8;
const int stala_ladownosc = 150;

void optymalne(int* C, int* W,int g)     //zastosujemy proste sortowanie bo mamy niewiele danych do sortowania 
{
    for (int i = 0;i <g-1;i++)  //od (pierwszego) do przed ostatniego
        for (int p = i+1;p < g;p++) //od (2) do ostatniego
            if (W[i] / C[i] < W[p] / C[p])  //jesli wartosc do ciezaru jest wiekszy to podmieniamy je  
                swap(W[i], W[p]), swap(C[i], C[p]);     //zamiana ciezarow i kosztow
}
void pakujemy(int* C, int* W, int ladownosc,bool* zaladowany, int g)  //funkcja wybierajaca kontenery na statek, zlozonosc 2*N -> N
{
    int ciezar = 0; //ciezar startowy 0 
    for (int i = 0;i < g;i++)   //przechodzimy przez wszystkie elementy
        if (ciezar + C[i] <= ladownosc) //jesli nie przekroczylismy ciezaru 
            ciezar += C[i],zaladowany[i] = true;    //to daodajemy i zaznaczamy
}
void wynik(int* C, int* W, bool* zaladowany,int g)    //Funkcja wypisujaca nasz wynik, zlozonosc tak samo N 
{
    int var = 0;    //wartosc 0 na starcie
    int ciezar = 0; //ciezar tak samo
    int counter = 1;    //indeksujemy elemnty od 1 
    cout << " Rozpis kontenerow na statku :  " << endl;
    for (int i = 0;i < g;i++) //przechodzimy po elementach 
    {
        if (zaladowany[i])  //jesli pakowalismy go do plecaka 
        {
            cout << counter << " kontener, z waga " << C[i] << " i wartoscia  " << W[i] << endl;    //wypisujemy go
            var += W[i];    // a tu sa operacje statystyczne na koniec
            ciezar += C[i];
            counter++;  //zliczamy kontenery zapakowane na statek
        }
    }
    cout << "Suma ciezaru na statku : " << ciezar << ", wartosc calego ladunku: " << var;   //wypisujemy ile ciezaru zapakaowalismy, oraz wartosc calego ladunku na statku
}

int main()
{
    int ladownosc;
    cout << "1. stala liczba kontenerow! " << endl;
    cout << "Podaj ladownosc statku : ";
    cin >> ladownosc;
    int C[k] = { 10,20,40,15,22,100,42,55 }; //ciezar kontenerow, uznajmy to za jakas jednostke typu tony xD
    int W[k] = { 100,200,330,112,330,634,221,167 };     //wartosci  poszczegolnych kontenerow
    bool zaladowany[k]; //zmienna pomocnicza ( chcemy pokazac ktore ladunki zapakowalismy );
    for (int i = 0;i < k;i++)   //falszujemy
        zaladowany[i] = false;
    optymalne(C, W,k); //sortujemy wartosciami ktore sie nam stosunkowo najlepiej oplacaja
    pakujemy(C, W, ladownosc,zaladowany,k);
    wynik(C, W, zaladowany,k);
    cout << "---------------------------------" << endl;
    cout << "2. stala ladownosc statku " << endl;
    cout << " Poidaj liczbe kontenerow!:  " << endl;
    int l;
    cin >> l;   //definiujemy liczbe kontenerow
    int* c = new int[l];    //alokujemy dynamicznie pamiec dla naszych tablic 
    int* w = new int[l];
    bool* zaladowany2 = new bool[l];
    for (int i = 0;i < l;i++)   //falszujemy jak wczesniej
        zaladowany2[i] = false;

    for (int i = 0;i < l;i++)
    {
        cout << "Podaj wage: "; //podajemy wage kolejnych kontenerow
        cin >> c[i];
        cout<< " Podaj wartosc konteneru: " << endl;
        cin >> w[i];    //i ich wartosc przy okazji
    }
    cout << "Obliczamy! " << endl;
    optymalne(c, w, l); //uzywamy tych samych funkcji, leczpodajemy zamiast parametru k ,   dlugosc l
    pakujemy(c, w, stala_ladownosc,zaladowany2, l); //oraz przekazuje nasza stała ładownosc
    wynik(c, w, zaladowany2, l);    //wypisujemy nasze wyniki!

    //Biorac sumarycznie wszystkie funkcje otrzymujemy zlozonosc (wynik)-> N +  (pakujemy) -> N + (sortowanie) -> u nas N^2, otrzymujemy zlozonosc
    // N+N+N^2 co daje nam zlozonosc rzedu N^2, jak widac nasza zlozonosc programu zalezy wylacznie od algorytmu sortowania, tak wiec
    // dobierajac dobry algorytm sortowania mozemy uzyskac niska zlozonosc naszego programu zachlannego.
    // Nalezy tez dodac, ze program w wiekszej czesci przypadkow znajdzie optymalny wynik lecz nie jest to regula,
    // dlatego jesli chcemy miec pewny najleepszy wynik, powinismy zastosowac algorytm dynamiczny
    
    cout << endl;

    
    


    
}
