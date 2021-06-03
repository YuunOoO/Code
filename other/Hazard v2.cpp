#include <iostream>
#include <cstdlib>
using namespace std;



int losowanie() //losowanie liczby 0-reszka 1-orzel(wygrana)
{
    int liczba = std::rand()%2;
    return liczba;
}


int main()
{
    bool strata = true;
    long long tmp_zysk, zysk, suma, n, counter;
    counter = suma = tmp_zysk = 0;
    zysk = 2;
    int x;
    srand(time(NULL));
    cout << "Program losowania" << endl;
   // cout << "Okresl ile ma kosztowac wpisowe : ";
  //  cin >> x;

    int sredni_zysk;
    cout << "podaj sredni zysk jaki chcesz przekroczyc : ";
    cin >> sredni_zysk;


    //int* tab_zyski = new int[n];
    //int* tab_rozklad = new int[n];

    for (;;)
    {
        counter++;  //licznik
       // suma -= x; //wklad

        while (losowanie() == 0)    //jesli reszki to zysk *2 
            zysk *= 2;

        //jesli przejdziemy daltej to znaczy ze wylosowalismy orla wiec konczymy ta probe 

        suma += zysk; //aktuaalizujemy saldo
       // tab_rozklad[i] = suma; //dodatek

        if (tmp_zysk < zysk)    //zapiszemy sobie najwiekszy zysk
            tmp_zysk = zysk;

        //tab_zyski[i] = zysk; //dodatek2
        zysk = 2;   //zerujemy zysk od nowa
        if (suma/counter>sredni_zysk)   //jesli wyjdziemy na plus
        {
            strata = false; //oznaczamy ze udalo sie wyjsc na plus
            cout << "w probie" << counter << " osiagnelismy sredni zysk " << sredni_zysk<<endl;
            sredni_zysk += 5; //tu sobie ustawiamy co chcemy !!!!!!!!!!!!!!!!!!!!!!!!! (chcial *2)
        }
    }
    if (!strata) //wypisujemy jesli sie udalo wyjsc na plus
    {
        cout << "Wyszlismy na plus i zyskalismy " << suma << "Zł Po " << counter << " Rzutach" << endl;
        cout << "Najwiekszy zysk wyniosl : " << tmp_zysk;
    }
    else
    {
        cout << "Nie udalo sie nam wyjsc na plus, ";
        cout << "Stracilismy " << suma << " Złotych :( " << endl;
    }

  

}
