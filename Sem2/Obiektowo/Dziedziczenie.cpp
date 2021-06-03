#include<iostream>
#include<string>

using namespace std;

class COsoba
{
public:
	COsoba();
	~COsoba();
	void czytaj_dane();
	void wyswietl_dane();

private:
	string nazwisko;
	string imie;
	string ulica;
};

class extended : public COsoba
{
public:
	extended();
	void wczytaj();
	void wypisz();
private:
	string nr_mieszkania;
	string miasto;
	string pesel;
};


COsoba::COsoba()
{
	nazwisko = "brak";
	imie = "brak";
	ulica = "brak";
}

COsoba::~COsoba()
{
}

int main() {
	int n;
	cout << " Podaj liczbe osob! : ";
	cin >> n;
	if (n <= 0) return 0;

	extended* wsk = new extended[n];

	for (int i = 0;i < n;i++)	//wczytywanie 
	{
		wsk[i].wczytaj();

	}
	for (int i = 0;i < n;i++)		//wypisywanie
	{
		wsk[i].wypisz();
	}

	cout << endl;
	
	return 0;
}



void COsoba::czytaj_dane()
{
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj ulice: ";
	cin >> ulica;
}

void COsoba::wyswietl_dane()
{
	cout << "Twoje dane:" << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Imie: " << imie << endl;
	cout << "Ulica: " << ulica << endl;
}

extended::extended()
{
	miasto = "brak";
	pesel = "brak";
	nr_mieszkania = "brak";
}

void extended::wczytaj()
{
	czytaj_dane();
	cout << "Podaj nr mieszkania !: "; cin >> nr_mieszkania;
	cout << "Podaj pesel !: "; cin >> pesel;
	cout << "Podaj nazwe miasta w ktorym mieszkasz !: "; cin >> miasto;
}

void extended::wypisz()
{	
	wyswietl_dane();
	cout << "Nr pesel : " << pesel << endl;
	cout << "Miasto zamieszkania : " << miasto << endl;
	cout << "Nr mieszkania : " << nr_mieszkania << endl;
}


