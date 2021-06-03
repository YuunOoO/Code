#include<iostream>
using namespace std;

class TestDestruktora
{
public:
	TestDestruktora();
	~TestDestruktora();
	void pokaz_liczba();
	void wypelnij_liczba(int a);
	void pokaz_tablice();
	void stworz_tablice(int size);	//inicjalizacja tablicy
	void dodaj_element(int y);	
	static int zliczaj;
private:
	int* tablica; //inicjalizujemy tablice
	int idx;	//zebysmy wiedzieli w ktore miejsce wlozyc lizcbe do tablicy
	int* liczba;	//jakas liczba dynamicznie
	bool czy_jest = false; // nw po co to ale mialo byc w zadaniu wiec uzyje

};
int TestDestruktora::zliczaj = 0;	//zmiena statyczna opisujaca ile mamy obiektow


int main() {
	int ile, p;
	cout << "Ile liczb chcesz podac? : ";
	cin >> ile;
	TestDestruktora ob;	//tworzymy obiekt
	int bb;
	ob.stworz_tablice(ile); //tworzymy tablice w obiekcie uwzgledniajac rozmiar
	for (int i = 0; i < ile; i++)
	{
		cout << "Podaj " << i + 1 << " Liczbe : ";
		cin >> p;
		ob.dodaj_element(p);				//dodjamy elementy do tablicy
	}
	ob.pokaz_tablice();		//wypisujemy je


	cout << "----------------------------" << endl;
	cout << "To samo ale dla obiektow dynamicznych!" << endl;
	cout << "Ile liczb chcesz podac? : " << endl;
	cin >> ile;
	TestDestruktora* wsk = new TestDestruktora; //obiekt dynamiczny
	wsk->stworz_tablice(ile);
	for (int i = 0; i < ile; i++)
	{
		cout << "Podaj " << i + 1 << " Liczbe : ";
		cin >> p;
		wsk->dodaj_element(p);		//dodjamy elementy do tablicy
	}
	wsk->pokaz_tablice(); //wyswietlamy
	cout << "----------------------------" << endl;


	ob.pokaz_liczba();
	cout << "podaj dowolna liczbe calkowita: ";
	cin >> bb;
	ob.wypelnij_liczba(bb);
	ob.pokaz_liczba();
	return 0;
}

TestDestruktora::TestDestruktora()
{
	liczba = new int;
	*liczba = 0;
	idx = 0;  //start tablicy od 0
	zliczaj++;	//zliczamy obiekty
	czy_jest = true; 
}

TestDestruktora::~TestDestruktora()
{
	cout << endl;
	cout << "dziala destruktor" << endl;
	delete liczba;
	cout << zliczaj << " Obiektow, zostalo usunietych!";
	delete[] tablica;
}

void TestDestruktora::pokaz_liczba()
{
	cout << *liczba << endl;
}

void TestDestruktora::wypelnij_liczba(int a)
{
	*liczba = a;
}


void TestDestruktora::pokaz_tablice()
{
	cout << "Twoje liczby to : " << endl;
	for (int i = 0;i < idx; i++)		//wypisujemy liczby
		cout << *(tablica + i) << " To Twoja " << i + 1 << " liczba " << endl;	//zwiekszajac adres o jeden (operujemy na wskazniku wiec zeby dostas sie do liczby w srodku uzywamy gwiazdki)
}

void TestDestruktora::stworz_tablice(int size)
{
	tablica = new int[size];	//tu przypisujemy jej miejsce w pamieci(wraz z naszym rozmiarem)
}

void TestDestruktora::dodaj_element(int y)
{
	*(tablica + idx) = y;	//dodajemy elementy w miejsce adresu wskaznika (+ musimy sie przesunac o ilosc elementow dodanych [idx]) 
	idx++;
}

