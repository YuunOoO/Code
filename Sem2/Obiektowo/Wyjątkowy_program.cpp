#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

struct Tblad_obliczeniowy {
	string opis_bledu;
};

double policz_pole_kuli(double promien);
double policz_objetosc_kuli(double promien);
double policz_pole_stozka(double promien, double tworzaca);
double policz_objetosc_prostopadloscianu(double a, double b, double c);
int main() {
	double r;
	cout << "podaj promien kuli: ";
	cin >> r;
	try
	{
		cout << "pole kuli o prmieniu " << r << " : " << policz_pole_kuli(r) << endl;
	}
	catch (Tblad_obliczeniowy wyjatek)
	{
		cout << "przechwycony wyjatek:" << wyjatek.opis_bledu << endl;

	}
	//objetosc kuli
	try
	{
		cout << "objetosc kuli o prmieniu " << r << " wynosi: " << policz_objetosc_kuli(r) << endl;
	}
	catch (Tblad_obliczeniowy wyjatek)
	{
		cout << "przechwycony wyjatek: " << wyjatek.opis_bledu << endl;

	}
	//pole stozka
	double l;
	cout << "Podaj tworzaca stozka: ";
	cin >> l;
	try
	{
		cout << "pole powierzchni stozka o prmieniu " << r<< " i tworzacej " << l << " wynosi: " << policz_pole_stozka(r, l) << endl;
	}
	catch (Tblad_obliczeniowy wyjatek)
	{
		cout << "przechwycony wyjatek: " << wyjatek.opis_bledu << endl;

	}
	//objetosc prostopadloscianu
	double c;
	cout << "Podaj trzecia wartosc: " << endl;
	cin >> c;
	try
	{
		cout << "objetosc prostopadloscianu o zadanych parametrach " << r << "," << l << " i " << c << " wynosi: " << policz_objetosc_prostopadloscianu(r, l, c) << endl;
	}
	catch (Tblad_obliczeniowy wyjatek)
	{
		cout << "przechwycony wyjatek: " << wyjatek.opis_bledu << endl;

	}
	return 0;
}

double policz_pole_kuli(double promien)
{
	cout << "obliczanie pola kuli" << endl;
	if (promien > 0) 
		return 4 * promien * promien * 3.14;
	else 
	{
		cout << "rzucenie wyjatku!" << endl;
		Tblad_obliczeniowy blad;
		blad.opis_bledu = "zerowy lub ujemny promien kuli!";
		throw blad;
	}
}

double policz_objetosc_kuli(double promien)
{
	cout << "Obliczam objetosc kuli!" << endl;
	if (promien > 0) 
		return (4 * M_PI * promien * promien * promien) / 3;
	else
	{
		cout << "rzucenie wyjatku!" << endl;
		Tblad_obliczeniowy blad_kuli;
		blad_kuli.opis_bledu = "zerowy lub ujemny promien kuli!";
		throw blad_kuli;
	}
}

double policz_pole_stozka(double promien, double tworzaca)
{
	cout << "Obliczam pole stozka!" << endl;
	if (promien > 0 && tworzaca > 0)
		return (M_PI * promien * promien + M_PI * promien * tworzaca);
	else
	{
		cout << "rzucenie wyjatku!" << endl;
		Tblad_obliczeniowy blad_stozka;
		blad_stozka.opis_bledu = "zerowy lub ujemny promien i tworzaca stozka!";
		throw blad_stozka;
	}
}

double policz_objetosc_prostopadloscianu(double a, double b, double c)
{
	cout << "obliczanie objetosci prostopadloscianu!" << endl;
	if (a > 0 && b > 0 && c > 0) 
		return a * b * c;
	else 
	{
		cout << "rzucenie wyjatku!" << endl;
		Tblad_obliczeniowy blad_prostopadloscianu;
		blad_prostopadloscianu.opis_bledu = "zerowe lub ujemne parametry a,b lub c!";
		throw blad_prostopadloscianu;
	}
}
