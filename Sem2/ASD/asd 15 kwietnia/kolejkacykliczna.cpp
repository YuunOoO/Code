#include <iostream>
using namespace std;

struct cykliczna
{
	string produkt;
	cykliczna* next = nullptr; //taka lista jak narazie
};
void push(cykliczna* glowny,cykliczna* &koniec, string element) 
{
	cykliczna* nowy = new cykliczna;	//dodajemy nowy element
	nowy->produkt = element;	//wypelniamy
	nowy->next = glowny;	//ma wskazywac na 1 element (zeby byl cykl)
	koniec->next = nowy;	//nastepne miejsce po koncu jest puste wiec go tam wrzucamy
	koniec = nowy;	//no i ustawiamy nasz koniec o jeden dalej dlatego mamy referencje w funkcji 
}
void wypisz(cykliczna* glowny,cykliczna* koniec)	//wypisujemy
{
	if(glowny->next==nullptr)	//jesli pusta 
	{
		cout << "Lista jest pusta" <<endl;
		return;
	}
	while (glowny != koniec)	//w przecwnym wypadku przechodzimy po kolei po liscie uzywajac wskaznika startowego
	{							//zatrzymamy sie az tak jakby zrobimy jeden cykl listy 
		cout << glowny->produkt << endl;	//wypisujemy
		glowny = glowny->next;	//do nastepnego
	}
	cout << glowny->produkt << endl; //ostatni produkt ktorego nie uwzglednilem wczesniej

}

int main()
{
   cout << "Program kolejki cyklicznej!"<<endl;
   cykliczna* glowny = new cykliczna;
   cykliczna* koniec = glowny; //nasz dodatkowy wskaznik ktory wskazuje na miejsce gdzie jeszzcze nie ma danych
   wypisz(glowny,koniec);
   cout << "----------- dodajemy lementy ------------" << endl;
   push(glowny,koniec,"Maka");  //dodajemy elementy w miejsce gdzie nie ma jeszcze danych 
   push(glowny, koniec,"Cukier");
   push(glowny, koniec,"Banany");
   push(glowny, koniec,"Szyneczka");
   push(glowny, koniec,"Monsterek");
   wypisz(glowny,koniec);


}
