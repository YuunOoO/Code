#include<iostream>
using namespace std;

class DaneTestowe
{
public:
	//static int zliczaj;
	DaneTestowe();
	~DaneTestowe();
	void pokaz_ilosc();
	void pokaz_rozmiar();
	void pokaz_znacznik();
	void wypelnij_ilosc();
	void wypelnij_rozmiar();
	void wypelnij_znacznik();
	void zapisz_obiekt();
	void zeruj_ilosc();
	void zeruj_rozmiar();
	static void dodaj_zliczanie();
	static int ile_zliczonych();
	friend void pokaz_obiekt(DaneTestowe& rr);
private:
	static int zliczaj_priv;
	int ilosc;
	float rozmiar;
	int znacznik;
};
void pokaz_obiekt(DaneTestowe& rr);
void dodaj_obiekt(DaneTestowe* obj);

void uzupelnij_obiekt(DaneTestowe* wsk);
DaneTestowe uzupelnij_obiekt(DaneTestowe obj);

void zeruj_ilosc(DaneTestowe* wsk);			 //nowa funkcjonalnosc klasy (po wskazniku) [metoda zeruj obiekt]
DaneTestowe zeruj_ilosc(DaneTestowe obj); //statycznie [zwraca typ obiekt]

void zeruj_rozmiar(DaneTestowe* wsk);		// -//-  jak wyzej
DaneTestowe zeruj_rozmiar(DaneTestowe obj);	//




//int DaneTestowe::zliczaj = 0;
int DaneTestowe::zliczaj_priv = 0;//zmienna statyczna prywatna

// Aby sprawdzic dzaialnie funkcji, trzeba usunac " // " w main'ie!

int main() {
	cout << "ilosc zliczonych: " << DaneTestowe::ile_zliczonych() << endl;
	DaneTestowe pierwszy;
	cout << "ilosc zliczonych: " << pierwszy.ile_zliczonych() << endl;
	DaneTestowe* ptr;
	ptr = new DaneTestowe;
	cout << "ilosc zliczonych: " << ptr->ile_zliczonych() << endl;
	ptr->dodaj_zliczanie();
	cout << "ilosc zlczonych: " << pierwszy.ile_zliczonych() << endl;
	ptr->wypelnij_ilosc();
	// ptr->zeruj_ilosc();		//testujemy zerowanie
	//zeruj_ilosc(ptr);	 //testowanie funkcji po wskazniku
	ptr->pokaz_ilosc();
	uzupelnij_obiekt(ptr);
	// ptr->zeruj_rozmiar(); //testujemy zerowanie
	//zeruj_rozmiar(ptr);		//testowanie funkcji po wskazniku
	ptr->pokaz_rozmiar();
	pierwszy = uzupelnij_obiekt(pierwszy);
	//pierwszy.zeruj_ilosc(); //testowanie zerowania ale przekazuja obiekt statyczny
	pierwszy.pokaz_ilosc();
	pierwszy.wypelnij_rozmiar();
	//pierwszy.zeruj_rozmiar();	//testowanie zerowania ale przekazuja obiekt statyczny
	pierwszy.pokaz_rozmiar();
	delete ptr;

	return 0;
}




DaneTestowe::DaneTestowe()
{
	this->ilosc = 0;
	rozmiar = 1;
	znacznik = 0;
	dodaj_zliczanie();
}

DaneTestowe::~DaneTestowe()
{
}
void DaneTestowe::zapisz_obiekt() {
	dodaj_obiekt(this);
}
void DaneTestowe::zeruj_ilosc()
{
	ilosc = 0;
}
void DaneTestowe::zeruj_rozmiar()
{
	rozmiar = 0;
}
void DaneTestowe::pokaz_ilosc() {
	cout << ilosc << endl;
}
void DaneTestowe::pokaz_rozmiar() {
	cout << rozmiar << endl;
}
void DaneTestowe::pokaz_znacznik() {
	cout << znacznik << endl;
}
void DaneTestowe::wypelnij_ilosc() {
	cout << "podaj potrzebna ilosc towaru w sztukach:";
	cin >> ilosc;
}
void DaneTestowe::wypelnij_rozmiar() {
	cout << "podaj potrzebny rozmiar w centymetrach:";
	cin >> rozmiar;
}
void DaneTestowe::wypelnij_znacznik() {
	if (znacznik == 0)
		znacznik = 1;
}
void DaneTestowe::dodaj_zliczanie() {
	zliczaj_priv = zliczaj_priv + 1;
}
int DaneTestowe::ile_zliczonych()
{
	return zliczaj_priv;
}
void uzupelnij_obiekt(DaneTestowe* wsk) {
	wsk->wypelnij_rozmiar();
}
DaneTestowe uzupelnij_obiekt(DaneTestowe obj) {
	obj.wypelnij_ilosc();
	return obj;
}
void zeruj_ilosc(DaneTestowe* wsk)
{
	wsk->zeruj_ilosc();
}
DaneTestowe zeruj_ilosc(DaneTestowe obj)
{
	obj.zeruj_ilosc();
	return DaneTestowe();
}
void zeruj_rozmiar(DaneTestowe* wsk)
{
	wsk->zeruj_rozmiar();
}
DaneTestowe zeruj_rozmiar(DaneTestowe obj)
{
	obj.zeruj_rozmiar();
	return DaneTestowe();
}
void pokaz_obiekt(DaneTestowe& rr) {
	rr.pokaz_ilosc(); 
	rr.pokaz_rozmiar();
	rr.pokaz_znacznik(); 
	rr.ilosc = 1;
	rr.rozmiar = 1;
}

void dodaj_obiekt(DaneTestowe* obj)
{
}

void wypelnij_ilosc(DaneTestowe* wsk) //funkcja wypelniania ilosci po wskazniku
{
	wsk->wypelnij_ilosc();
}

void wypelnij_rozmiar(DaneTestowe obj)		//funkcja wypelniania rozmiaru po przekazaniu obiektu 
{
	obj.wypelnij_rozmiar();
}
