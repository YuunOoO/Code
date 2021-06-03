#include <iostream>
using namespace std;

struct lista //nasza struktura listy
{
	string produkt;		//produkt w liscie
	lista* next=0;	//wskaznik na nastepny element
};

void dodaj(lista* pierwszy, string element)	//funkcja dodajaca element (przekazujemy wskaznik na poczatek listy i nazwe elementu)
{
	//akurat ustawilem pierwszy jako takiego wartownika, ktorego nie bede ruszac
	lista* nowy = new lista;	//tworzymy nowy element listy i go uzupelniamy
	nowy->produkt = element; //nazwa
	nowy->next = 0;	//wskaznik
	if (pierwszy->next == 0)	//asekuracyjnie gdy dodajemy pierwszy element
	{
		pierwszy->next = nowy; //pierwszy wskazuje na 2 element tablicy
		return;
	}
	lista* robotaju = pierwszy; //zmienna robocza
	while (robotaju->next != 0)//jesli nie jestesmy na koncu listy
		robotaju = robotaju->next;	//przesuwamy sie o jeden dalej
	robotaju->next = nowy;	//jak juz bedziemy na kocnu to koniec listy zaczyna wskazywac na nasz nowy elementy (przedluzamy liste)
	return; // w sumie tego nie trzeba
}
void wypisz(lista* pierwszy)
{
	if (pierwszy->next == 0) cout << "Lista jest aktualnie pusta!" << endl;	//jesli lista jest pusta
	while (pierwszy != 0)	//w przeciwnym wypadku dopuki wskaznik nie wskazuje na null
	{
		cout << pierwszy->produkt << endl; //wypisujemy element
		pierwszy = pierwszy->next; //przesuwamy sie o jeden dalej
	}
}
void sprawdz(lista* pierwszy, string klucz)
{
	int counter = 0; //ustalamy licznik na 0
	while (pierwszy != 0) //jesli nie wyszlismy poza zakres
	{
		if (pierwszy->produkt == klucz) //jesli znajdziemy produkt
		{
			cout << "Produkt znajduje sie na liscie i jest pod numerem : " << counter<<endl; //wypisujemy ze jest i na ktorej pozycji
			return;
		}
		counter++; //licznik ++ dopiero w tym miejscu poniewaz nasza pierwszy element listy to tak jakby pusty wartownik
		pierwszy = pierwszy->next; //przesuwamy sie po liscie
	}
	cout << "Ten produkt nie znajduje sie na liscie" << endl;
	//jesli nie znajdziemy go na liscie to po prostu go nie ma
}

int main()
{
	lista* pierwszy = new lista;	//alokujemy pamiec dla naszej listy
	wypisz(pierwszy);	//sprawdzamy czy jest pusta

	cout << "----Dodawanie artykulow w trakcie-------" << endl; //dodajmey
	dodaj(pierwszy, "Mleko");
	dodaj(pierwszy, "Kielbasa");
	dodaj(pierwszy, "Cukier");
	dodaj(pierwszy, "Woda");
	dodaj(pierwszy, "Maka");
	dodaj(pierwszy, "Szynka");
	dodaj(pierwszy, "Monsterek");
	dodaj(pierwszy, "Laysy");
	dodaj(pierwszy, "Mandarynki");
	dodaj(pierwszy, "Banany");
	cout << "Lista aktualnych artykulow spozywczych! " << endl;
	wypisz(pierwszy);	//wypisujemy
	cout << "---------------------------" << endl;
	cout << "Sprawdzamy czy 'Cukier' znajduje sie na liscie" << endl;
	sprawdz(pierwszy, "Cukier");	//sprawdzmay czy jest Cukier (jest)
	cout << "---------------------------" << endl;
	cout << "Sprawdzamy czy 'Arbuz' znajduje sie na liscie" << endl;
	sprawdz(pierwszy, "Arbuz"); //sprawdzamy czy jest arbuz (arbuza nie ma )
	cout << "---------------------------" << endl;
	cout << "znowu wypisujemy zawartosc(takie bylo polecenie w zadaniu)" << endl;
	wypisz(pierwszy); //nie wiem po co ale wypisujemy jeszcze raz


}

