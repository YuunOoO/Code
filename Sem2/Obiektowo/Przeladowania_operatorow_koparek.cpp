#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Test_funkcyjny {
private:
	char x, y;
	void zakres(char a, char b);
public:
	//Test_funkcyjny(int p);
	Test_funkcyjny();
	char operator()(char k);
};
class Tablica_int {
private:
	//int tab[10];
	int rozmiar;
	float* tablica;
	void init (int r);
public:
	Tablica_int();
	float& operator[](unsigned int indeks);
	void wypelnij();
	void pokaz();
};


class Testowa {
private:
	string nazwa;
	int rozmiar;
	int numer;
	int* tab;
public:
	Testowa();
	Testowa& operator=(const Testowa& wzor);
	void dodaj_nazwa(string s);
	void dodaj_numer(int nr);
	void dodaj_tablice(int tab[], int r);
	void wypelnij_tablice();
	void pokaz();
};

int main() {
    cout << "ZADANIE 1" << endl;
	Testowa ob1, ob2;
	int liczba;
	string napis;
	cout << "Podaj nazwe obiektu: ";
	cin >> napis;
	cout << "Podaj numer obiektu: ";
	cin >> liczba;
	int tmp[4] = { 20,40,60,80 };
	ob1.dodaj_nazwa(napis);
	ob1.dodaj_numer(liczba);
	ob1.dodaj_tablice(tmp, 4);
	ob1.pokaz();
	cout << endl;
	ob2 = ob1;
	ob2.pokaz();
	ob2.wypelnij_tablice();
	ob2.pokaz();

    cout << "----------------------------" << endl << endl;
    cout << "ZADANIE 2" << endl;

	Tablica_int nowa_tab;
	for (int i = 0; i < 10; i++) 
		nowa_tab[i] = i + 1.14;
	nowa_tab.pokaz();
	nowa_tab.wypelnij();
	nowa_tab.pokaz();

    cout << "ZADANIE 3" << endl;

    cout << "----------------------------" << endl << endl;

    Test_funkcyjny nowy;
    cout << nowy('d');
    return 0;
}

Testowa::Testowa()
{
	nazwa = "nowa";
	numer = 0;
}

Testowa& Testowa::operator=(const Testowa& wzor)
{
	if (&wzor != this) {
		nazwa = wzor.nazwa;
		numer = wzor.numer;
		tab = wzor.tab;
		rozmiar = wzor.rozmiar;
	}
	return *this;
}

void Testowa::dodaj_nazwa(string s)
{
	nazwa = s;
}

void Testowa::dodaj_numer(int nr)
{
	numer = nr;
}

void Testowa::pokaz()
{
	cout << "Nazwa obiektu to: " << nazwa << endl;
	cout << "Numer obiektu to: " << numer << endl;
	for (int i = 0; i < rozmiar; i++) 
		cout << tab[i] << " ";
	cout << endl;
}

void Testowa::wypelnij_tablice()
{
	for (int i = 0; i < rozmiar; i++)
		tab[i] = rand() % 100;
}
void Testowa::dodaj_tablice(int tabex[], int r)
{
	tab = new int[r];
	rozmiar = r;
	for (int i = 0; i < r; i++) {
		tab[i] = tabex[i];
	}
}
float& Tablica_int::operator[](unsigned int indeks)
{
	return tablica[indeks];
}
void Tablica_int::wypelnij() {
	for (int i = 0; i < rozmiar; i++)
		tablica[i] = rand() % 100;
}
void Tablica_int::pokaz() {
	for (int i = 0; i < rozmiar; i++)
		cout << tablica[i] << " ";
	cout << endl;
}
void Tablica_int::init(int r)
{
	rozmiar = r;
	tablica = new float[rozmiar];
}
Tablica_int::Tablica_int()
{
	int r;
	cout << "Podaj rozmiar: ";
	cin >> r;
	init(r);
}
void Test_funkcyjny::zakres(char a, char b)
{
	x = a;
	y = b;
}
Test_funkcyjny::Test_funkcyjny()
{
	char a, b;
	cout << "Pierwsza wartosc zakresu: " << endl;
	cin >> a;
	cout << "Druga wartosc zakresu: " << endl;;
	cin >> b;
	zakres(a, b);
}
char Test_funkcyjny::operator()(char k)
{
	if (k > x && k < y) return k;
	else return '-';
}