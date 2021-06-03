#include <iostream>

using namespace std;
const int N = 10;

int main()
{
	int stopien,pierwiastek, narzut = 0;	//wiecej zmiennych zeby bylo czytelne
	cout << "Metodą Hornera oblicz wartosc wielomianu p(x)=a0+a1x+a2x2+..+anxn "<<endl;
	cout << "wybierz stopien wielomianu!(Xn)";
	cin >> stopien;
	int tabA[N];
	cout << "Prosze podac wspolczynniki wielomianu przy nastepujacych potegach:" << endl;
	for (int i = 0; i < stopien; i++)
	{
		cout << "Wspolczynnik przy stopniu X^" << stopien - i << " : ";
		cin >> tabA[i];
	}
	cout << " Prosze podac pierwiastek wielomianu : ";
	cin >> pierwiastek;
	pierwiastek *= -1;	//minusujemy nasz pierwiastek [pozniej to bedzie mnoznik]

	narzut = tabA[0];
	for (int i = 1; i < stopien; i++)
	{
		narzut *= pierwiastek;
		tabA[i] -= narzut;      //odejmujemy w tej samej tablicy zeby nie tworzyc nowych zmiennych[po prostu obnizamy o jeden stopien pozniej]
		narzut = tabA[i];	//przepisujemy narzut
	}
	for (int i = 0;i < stopien-1;i++)
	{
		if (tabA[i] == 0)
			continue;		//jakby nam wyszlo 0 to po co wypisywac?

		if (tabA[i] > 0) cout << "+";		//znak
		cout << tabA[i];
		cout << "X^" << stopien - i-1;
	}
	cout << "reszta wynosi: " << narzut;
}
//zlozonosc 3*N
