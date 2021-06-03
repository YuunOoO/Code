#include<iostream>
using namespace std;
class Instrument
{
public:
	virtual void wydaj_dzwiek() = 0;
};
class Strunowe : public Instrument
{
public:
	virtual void ustaw_struny() = 0;
};
class Klawiszowe : public Instrument
{
public:
	virtual void ustaw_klawisze() = 0;
};
class Organy : public Klawiszowe
{
public:
	void wydaj_dzwiek();
	void ustaw_klawisze();
};
class Skrzypce : public Strunowe
{
public:
	void wydaj_dzwiek() ;
	void ustaw_struny() ;
};
class Traba : public Instrument
{
public:
	void wydaj_dzwiek();
};
void Traba::wydaj_dzwiek()
{
	cout << "dzwiek charakterystyczny dla traby" << endl;
}
void Skrzypce::wydaj_dzwiek()
{
	cout << "dzwiek charakterystyczny dla skrzypiec" << endl;
}
void Skrzypce::ustaw_struny()
{
	cout << "Ustawiono struny!" << endl;
}
void Organy::wydaj_dzwiek()
{
	cout << "dzwiek charakterystyczny dla organow" << endl;
}

void Organy::ustaw_klawisze()
{
	cout << "Ustawiono klawisze!" << endl;
}

void uzyj_instrument(Instrument& instrumencik);
void wypoleruj(Instrument* pointer);
void wyrzuc(Strunowe& zlom);

int main() {
	Skrzypce nowe_skrzypki;
	Traba stara_trabka;
	Organy organki;
	/*teraz deklaracja wskaŸnika*/
	Instrument* wskIns;
	/*inicjalizacja wskaŸnika*/
	cout << "wywo³anie funkcji z obiektu za pomoca wskaznika:" << endl;
	wskIns = &nowe_skrzypki;
	wskIns->wydaj_dzwiek();
	wskIns = &stara_trabka;
	wskIns->wydaj_dzwiek();
	wskIns = &organki;
	wskIns->wydaj_dzwiek();
	cout << "przekazanie referencji do funkcji,";
	cout << "zachowanie takie samo jak w przypadku wskaznika : " << endl;
	uzyj_instrument(nowe_skrzypki);
	uzyj_instrument(stara_trabka);
	uzyj_instrument(organki);
	cout << "--------------------" << endl;
	cout << "Test skrzypek i organek!" << endl;
	nowe_skrzypki.ustaw_struny();
	organki.ustaw_klawisze();
	cout << "Test klasy" << endl;
	Strunowe* ptr1 = &nowe_skrzypki;
	ptr1->ustaw_struny();
	Klawiszowe* ptr2 = &organki;
	ptr2->ustaw_klawisze();
	cout << "----------------------" << endl;
	wypoleruj(wskIns);
	wyrzuc(nowe_skrzypki);

	

	return 0;
}

void uzyj_instrument(Instrument& instrumencik) {
	instrumencik.wydaj_dzwiek();
}

void wypoleruj(Instrument* pointer)
{
	cout << "Wypolerowales instrument"<<endl;
}

void wyrzuc(Strunowe& zlom)
{
	cout << "Wlasnie wyrzuciles instrument"<<endl;
}
