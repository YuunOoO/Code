// poleobjektowo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>

using namespace std;

class Cpole
{
public:
	Cpole();
	Cpole(float aa, float bb);
	Cpole(float aa, float bb, float rr);
	void przypisz_promien(float rr);
	float Policz_pole_prostokata();
	float Policz_pole_troj();
	float Policz_pole_kola();
	float pole_trapezu();
	~Cpole();

private:
	float x, y;
	float r;
};

int main()
{
	float a, b, rrr;
	char wybor;
	do
	{
		system("CLS");
		cout << " Wybierz czego pole chcesz liczyc ! : " << endl;
		cout << " 1. Prostokat" << endl;
		cout << " 2. Trojkat " << endl;
		cout << " 3. Kolo " << endl;
		cout << " 4. Trapez" << endl;
		cin >> wybor;
		switch (wybor)
		{
			case '1':
			{
				cout << "Podaj dlugosci bokow a, b: ";
				cin >> a >> b;
				Cpole obiekt1(a, b);
				cout << "Pole prostokata wynosi : " << obiekt1.Policz_pole_prostokata() << endl;
				break;
			}
			case '2':
			{
				cout << "Podaj dlugosci podstawy i wysokosci! : " << endl;
				cin >> a >> b;
				Cpole obiekt2(a, b);
				cout << " Pole trojkata wynosi : " << obiekt2.Policz_pole_troj() << endl;
				break;
			}
			case '3':
			{
				cout << "Podaj dlugosc promienia!";
				cin >> rrr;
				Cpole* wsk_ob;
				wsk_ob = new Cpole;
				wsk_ob->przypisz_promien(rrr);
				cout << " Pole kola wynosi : " << wsk_ob->Policz_pole_kola()<<endl;
					break;
			}
			case '4':
			{
				cout << "Podaj dlugosc podstaw a , b, oraz wysokosci trapezu! : ";
				cin >> a >> b >> rrr;
				Cpole* wsk_obiekt;
				wsk_obiekt = new Cpole(a, b, rrr);
				cout << "Pole trapezu wynosi : " << wsk_obiekt->pole_trapezu() << endl;
				break;
				
			}

			default:
			{
				cout << "Chyba Cie pojebalo!"<<endl;
				break;
			}
		}
		cout << "Kontynuowac prace programu? (t/n)";
		cin >> wybor;

	} while (wybor=='t');
	
}

Cpole::Cpole()
{
	r = 0;
}

Cpole::Cpole(float aa, float bb)
{
	x = aa;
	y = bb;

}

Cpole::Cpole(float aa, float bb, float rr)
{
	x = aa;
	y = bb;
	r = rr;
}

void Cpole::przypisz_promien(float rr)
{
	r = rr;
}

float Cpole::Policz_pole_prostokata()
{
	return x * y;
}

float Cpole::Policz_pole_troj()
{
	return x * y / 2;
}

float Cpole::Policz_pole_kola()
{
	return 3.14*r*r;
}

float Cpole::pole_trapezu()
{
	return (x + y) / 2 * r;
}

Cpole::~Cpole()
{
}

