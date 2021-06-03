#include <iostream>
#include <cmath>

using namespace std;

const int N = 25;

bool pierwsza(int a)			//funkcja sprawdzania czy liczba jest pierwsza
{
	if (a <= 1) return false;
	for (int i = 2; i <= sqrt(a);i++)   //ograniczamy przez pierwiastek bo wyzej nie znajdziemy dzielnika
		if (a % i == 0) return false;	//sprawdzamy podzielnosc przez kazda z liczb ponizej
	return true;
	//zlozonosc pierwiastek z liczby
}

int main()
{
	cout << " Znajdź wszystkie liczby pierwsze nie większe od danej liczby naturalnej N ";
	for (int i = 1; i <= N;i++)		//mielimy wszystkie liczby
	{
		if (pierwsza(i)) cout << i << endl;		//jesli jest pierwsza to wypisujemy
	}
	//zlozonosc N main'u
	return 0;
}
//calkowita zlozonosc N * sqrt(N) [nie uwzgledniajac zlozonosci funkcji modulo]
