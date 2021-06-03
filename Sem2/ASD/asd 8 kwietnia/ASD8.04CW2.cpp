#include <iostream>
using namespace std;
//wrazie problemow z kompilacja, zalecam zamienic wszystkie nullptr na 0 lub uzyc nowszego kompilatora!

struct lista
{
    string produkt;	//nazwa produktu
    lista* next=nullptr; //nastepny
    lista* prev=nullptr; //poprzedni
};

void dodaj(lista* start, string element )  //dodawanie na koniec wiec nie trzeba nic kombinowac
{
	lista* nowy = new lista;	//nowy element
	nowy->produkt = element;	//wypelniamy

	while (start->next != nullptr)	//przechodzimy na koniec tak jak w jednokierunkowaej
		start = start->next;

	start->next = nowy;	//dodajemy w dwie strony wskazniki (nastepny i poprzedni)
	nowy->prev = start;
}

void wypisz(lista* start)
{
	if (start->next == nullptr)	//sprwdzamy czy jest pusta
	{
		cout << "Lista jest pusta!" << endl;
		return;
	}
	while (start != nullptr) //dopuki nie jest pusta
	{
		cout << start->produkt << endl; //wypisujemy
		start = start->next;	//przechodzimy do nastepnego produktu
	}
}
void przestaw(lista* start, int x, int y)
{
	lista* robotaju1 = start;	//zmienne robocze
	lista* robotaju2 = start;
	for (int i = 0; i < x; i++)	//ustawiamy sie na elemencie numer x
		robotaju1 = robotaju1->next;
	for (int i = 0; i < y; i++)	//ustawiamy sie na elemencie numer y
		robotaju2 = robotaju2->next;
	
	string tmp = robotaju1->produkt;	//typowa podmiana z uzyciem trzeciej zmiennej [zamieniamy tylko produkt a wskaznikow nie dotykamy]
	robotaju1->produkt = robotaju2->produkt;
	robotaju2->produkt = tmp;

}
void usun(lista* start, int x)
{
	lista* robotaju = start;	//zmienna pomocnicza
	for (int i = 0;i <x;i++)	//ustawiamy sie na elemencie ktory chcemy usunac
		robotaju = robotaju->next;

	lista* przed = robotaju;	//dwie zmienne zeby siebie ustawic na elementach ktore sa przed i po elemencie ktory chcemy usunac
	lista* po = robotaju;
	przed = przed->prev;	//cofamy sie o jedno
	po = po->next;	//jeden do przodu
	przed->next = po;	//poprzedni wskaznik wskazuje na nastepny element 
	po->prev = przed;	//nastepny wskaznik wskazuje na poprzedni element
	delete robotaju;	//usuwamy srodkowy element z pamieci 

}

int main()
{
	lista* pierwszy = new lista;	//alokujemy pamiec dla naszej listy dwukierunkowej
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
	cout << "Przestawiamy 2 z 7 elementem naszej listy" << endl;
	przestaw(pierwszy, 2, 7);	//zamiana
	wypisz(pierwszy);	//wypisujemy
	cout << "---------------------------" << endl;
	cout << "Usuwamy 5 element naszej listy " << endl;
	usun(pierwszy, 5);	//usuwamy
	wypisz(pierwszy);	//wypisujemy

}

