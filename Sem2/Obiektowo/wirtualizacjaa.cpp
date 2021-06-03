#include<iostream>
using namespace std;

class Instrument
{
public:
	virtual void wydaj_dzwiek() = 0;
	virtual void nadaj_nazwe(string nazwa) = 0;
	void wypisz();	//metoda do wypisywanie wszystkich nazw
	string name;	//zmienna widoczna dla wszystkich zeby bylo mniej pisania
};

class Organy : public Instrument
{
public:
	void wydaj_dzwiek() override;
	void nadaj_nazwe(string nazwa) override;
private:
	
};
class Skrzypce : public Instrument
{
public:
	void wydaj_dzwiek() override;
	void nadaj_nazwe(string nazwa) override;
private:
	
};
class Traba : public Instrument
{
public:
	void wydaj_dzwiek() override;
	void nadaj_nazwe(string nazwa) override;
private:
	
};

void uzyj_instrument(Instrument& instrument);

int main() {
	//Instrument obiekt_instrument;
	Skrzypce nowe_skrzypki;
	Organy organki;
	Traba stara_trabka;
	//obiekt_instrument.wydaj_dzwiek();
	nowe_skrzypki.wydaj_dzwiek();
	organki.wydaj_dzwiek();
	stara_trabka.wydaj_dzwiek();
	//wszystko działa zgodnie z oczekiwaniami
	Instrument* wsk_ins;
	cout << endl << "wywolanie fukcji z obiektu za pomoca wskaznika:" << endl;
	//wsk_ins = &obiekt_instrument;
	//wsk_ins->wydaj_dzwiek();
	wsk_ins = &nowe_skrzypki;
	wsk_ins->wydaj_dzwiek();
	wsk_ins = &organki;
	wsk_ins->wydaj_dzwiek();
	wsk_ins = &stara_trabka;
	wsk_ins->wydaj_dzwiek();
	cout << endl << "przekazanie referencji do funkcji:" << endl;
	//uzyj_instrument(obiekt_instrument);
	uzyj_instrument(organki);
	uzyj_instrument(nowe_skrzypki);
	uzyj_instrument(stara_trabka);
	cout << "--------test-----------" << endl;
	wsk_ins = &nowe_skrzypki;
	wsk_ins->nadaj_nazwe("Skrzypcee");
	wsk_ins->wypisz();

	return 0;
}




void Organy::wydaj_dzwiek()
{
	cout << "dzwiek charakterystyczny dla organow" << endl;
}

void Organy::nadaj_nazwe(string nazwa)
{
	name = nazwa;
}

void Skrzypce::wydaj_dzwiek()
{
	cout << "dzwiek charakterystyczny dla skrzypiec" << endl;
}

void Skrzypce::nadaj_nazwe(string nazwa)
{
	name = nazwa;
}

void Traba::wydaj_dzwiek()
{
	cout << "dzwiek charakterystyczny dla traby" << endl;
}

void Traba::nadaj_nazwe(string nazwa)
{
	name = nazwa;
}

void uzyj_instrument(Instrument& instrument)
{
	instrument.wydaj_dzwiek();
}

void Instrument::wypisz()
{
	cout << name << endl;
}
