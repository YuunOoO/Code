#include<iostream>
#include<vector>
#include<functional>
using namespace std;

void pokaz();
void pierwsza();
void druga();
int zwieksz(int wartosc);
int policz(int pierwsza, int druga);
int funkcja_dodaj(int pierwsza_l, int(*zmien)(int, int));
void trio(int(*jeden)(), int(*dwa)(), int(*trzy)());
int przechwyc_wartosc(int(*przechwyt)())
{
	int x; 
	x = przechwyt();
	return x;
}
int x1()
{
	int var;
	cout << " Podaj wartosc: ";
		cin >> var;
	cout << endl;
	return var;
}
int x2()
{
	int x, y;
	cout << "Podaj 2 warosci"<<endl;
	cin >> x >> y;
	return x * y;
}
int x3()
{
	double x, y;
	cout << "Podaj 2 warosci" << endl;
	cin >> x >> y;
	int w = int(x / y);
	return int(x - w * y);
}

int main() {
	void(*wsk_pusta)();
	int(*wsk_dwa)(int, int);
	using wsk_tab = void(*)();
	wsk_tab tablica[3];
	tablica[0] = pokaz;
	tablica[1] = pierwsza;
	tablica[2] = druga;
	for (int i = 0; i < 3; i++) {
		tablica[i]();
	}
	using wsk_mux = int(*)();
	wsk_mux tab[3];
	tab[0] = x1;
	tab[1] = x2;
	tab[2] = x3;
	wsk_pusta = pokaz;
	wsk_dwa = &policz;
	int wartosc;
	wsk_pusta();
	cout << "Podaj dowolna liczbe calkowita: ";
	cin >> wartosc;
	auto* wsk_jeden = &zwieksz;
	cout << "wartosc po zwiekszeniu: " << wsk_jeden(wartosc) << endl << endl;
	cout << "wynik uzycia funkcja_dodaj: " << funkcja_dodaj(wartosc, wsk_dwa)<<endl;
	cout << "------------Zad 1------------ " << endl;
	trio(tab[0], tab[1], tab[2]);
	cout << "test przechwytywania";
	cout <<przechwyc_wartosc(tab[0])<<endl;

	return 0;
}

void pokaz()
{
	cout << "Podaj wartosc: ";
	double wart;
	cin >> wart;
	cout << endl << "Podana przez Ciebie wartosc to: " << wart << endl;
}

void pierwsza()
{
	cout << "Funkcja o nazwie pierwsza" << endl;
}

void druga()
{
	cout << "Funkcja o nazwie druga" << endl;
}

int zwieksz(int wartosc)
{
	int liczba;
	cout << "Podaj ile razy zwiekszyc wartosc: ";
	cin >> liczba;
	return wartosc * liczba;
}

int policz(int pierwsza, int druga)
{
	return pierwsza + druga;
}

int funkcja_dodaj(int pierwsza_l, int(*zmien)(int, int))
{
	int liczba1;
	int liczba2;
	cout << "Podaj pierwsza liczba calkowita: ";
	cin >> liczba1;
	cout << "Podaj druga liczba calkowita: ";
	cin >> liczba2;
	return pierwsza_l + zmien(liczba1, liczba2);
}

void trio(int(*jeden)(), int(*dwa)(), int(*trzy)())
{
	cout <<jeden()<<endl;
	cout << dwa() << endl;
	cout << trzy() << endl;
	return ;
}

