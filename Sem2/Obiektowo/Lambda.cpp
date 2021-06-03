#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include <functional>
#include <utility>
using namespace std;

void wypisz(vector<double> wektor)
{
	for (int i = 0; i < wektor.size();i++)
		cout << wektor[i] << endl;
}

void transform_2(vector<double>& wektor, function<double(double)> transformFn)
{
	for (int i = 0;i < wektor.size();i++)
		wektor[i] = transformFn(wektor[i]);
}

void algorytm_transform(vector<double>& wektor, double(*transformuj)(double));
void transform(vector<double>& wektor, function<double(double)> transformFn)
{
	for (int i = 0; i < wektor.size(); i++)
		wektor[i] = transformFn(wektor[i]);
}
void sprawdz(vector<double>& wektor, function<bool(double)> transformFn)
{
	for (int i = 0; i < wektor.size(); i++)
	{
		bool dodatnia  = transformFn(wektor[i]);
		if (dodatnia) cout << wektor[i] << " dodatni " << endl;
		else
			cout << wektor[i] << " ujemny " << endl;
	}
}


int main() {
	srand(time(NULL));
	int pierwsza, druga, lokalna, dlugosc, a, b;
	cout << "Podaj dowolna wartosc calkowita: ";
	cin >> pierwsza;
	cout << "Podaj druga dowolna wartosc calkowita: ";
	cin >> druga;

	cout << "wynik dzialania lambdy: " << [pierwsza](int aa)mutable
	{
		cout << "podaj dodatkowa liczbe calkowita: ";
		int dodatkowa;
		cin >> dodatkowa;
		pierwsza = pierwsza - dodatkowa;
		return pierwsza * aa;
	}(druga);
	cout << endl;

	cout << endl;
	cout << "--------------------------" << endl;
	cout << "zad 1" << endl;
	cout << "Podaj 3 wartosci: " << endl;
	cin >> pierwsza >> druga >> lokalna;
	cout << "Suma liczb wynosi: " << [lokalna](int pierwszy, int drugi) {return pierwszy + lokalna + drugi;}(pierwsza, druga) << endl;
	cout << "zad 2 " << endl;
	cout << "Podaj dlugosc a nastepnie przedzial losowanych liczb(a,b) : " << endl;
	cin >> dlugosc >> a >> b;
	vector<double> wektoriusz;
	for (int i = 0;i < dlugosc;i++)
		wektoriusz.push_back((rand() % b) + a);
	wypisz(wektoriusz);
	cout << endl;
	algorytm_transform(wektoriusz, [](double wartosc) {return wartosc *= -1; });
	cout << "wektor po transformacji:" << endl;
	wypisz(wektoriusz);
	cout << endl << "zad 3 " << endl;
	cout << "Podaj element: " << endl;
	double element;
	cin >> element;
	transform(wektoriusz, [element](double var) {
		return var *= element;
		});
	cout << endl;
	wypisz(wektoriusz);
	cout << "-------------------------" << endl;
	cout << " zad4 " << endl;
	sprawdz(wektoriusz, [element](double wartosc) {
		if (wartosc >= 0) return true;
		else
			return false;
		});
	cout << "-------------------------" << endl;
	cout << " zad5 " << endl;
	double rozmiar = wektoriusz.size();
	transform_2(wektoriusz, [rozmiar](double wartosc) {
		return  1/( wartosc * rozmiar);
		});
	wypisz(wektoriusz);

	return 0;
}

void algorytm_transform(vector<double>& wektor, double(*transformuj)(double))
{
	for (int i = 0; i < wektor.size(); i++)
		wektor[i] = transformuj(wektor[i]);
}

