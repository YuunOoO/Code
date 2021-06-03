#include<iostream>
#include<vector>
#include<functional>
#include<cstdlib>
using namespace std;

bool zgiecie_ramienia();
bool zgiecie_przedramienia();
bool zgiecie_chwytaka();
bool obrot_ramienia();
bool obrot_przedramienia();
bool obrot_chwytaka();

int main() {
	
	using wsk_tab = bool(*)();
	wsk_tab tab[100];
	int wybor = 0;
	int i = 0;
	while (wybor != 7)
	{
		cout << "-------------------------------" << endl;
		cout << "Program sterowania robotem!!!" << endl;
		cout << "Wybierz opcje wykonania: " << endl;
		cout << "1. Zgiecie ramienia" << endl;
		cout << "2. Zgiecie przedramienia" << endl;
		cout << "3. Zgiecie chwytaka" << endl;
		cout << "4. Obrot ramienia" << endl;
		cout << "5. Obrot przedramienia" << endl;
		cout << "6. Obrot chwytaka" << endl;
		cout << "7. Zakonczenie procesu wybierania i uruchomienie procedury" << endl;
			cin >> wybor;

		switch (wybor)
		{
		case 1:
			tab[i] = zgiecie_ramienia;
			break;

		case 2:
			tab[i] = zgiecie_przedramienia;
			break;

			//...
		case 3:
			tab[i] = zgiecie_chwytaka;
			break;

		case 4:
			tab[i] = obrot_ramienia;
			break;
		case 5:
			tab[i] = obrot_przedramienia;
			break;
		case 6:
			tab[i] = obrot_chwytaka;

			break;
		}
		i++;
		system("cls");
	}
	cout << "Wyszedles z menu wyboru!" << endl;
	for (int k=0; k<i-1;k++)
	{
		tab[k]();
	}
	return 0;
}



bool zgiecie_ramienia()
{
	cout << "Zgieto ramie" << endl;
	return true;
}

bool zgiecie_przedramienia()
{
	cout << "Zgieto przedramie" << endl;
	return true;
}

bool zgiecie_chwytaka()
{
	cout << "Zgieto chwytak" << endl;
	return true;
}

bool obrot_ramienia()
{
	cout << "Obrocono ramie" << endl;
	return true;
}

bool obrot_przedramienia()
{
	cout << "Obrocono przedramie" << endl;
	return true;
}

bool obrot_chwytaka()
{
	cout << "Obrocono chwytak" << endl;
	return true;
}
