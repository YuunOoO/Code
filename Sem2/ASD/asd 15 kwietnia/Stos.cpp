#include <iostream>
using namespace std;

struct stos {
    string produkt;
    stos* next = nullptr;
};

bool empty(stos* top)
{
    if (top->next == nullptr) return true;  //jesli wskazujemy na null to znaczy ze nie ma kolejnego elemntu 
    return false; //w przeciwnym wypadku cos jest 
}
void sprawdz(stos* top)
{
    if (empty(top)) //w zaelznosci co nam zwroci funkcja empty to wypisujemy
        cout << "Stos jest pusty" << endl;
    else
        cout << "Stos nie jest pusty!" << endl;
}
void push(stos*& top, string element)   //przekazujemy przez referencje poniewaz nasz wskaznik na 1 element bedzie sie ciagle zmienial 
{
    stos* nowy = new stos;  //nowy elementy stostu
    nowy->produkt = element;  //wypelniamy
    nowy->next = top;   //wrzucamy na stos
    top = nowy; //przypisujemy temu elementowi nasz wskaznik top [bo rozpoczyna on teraz stos cnie]
}
void pop(stos*& top) //sciagamy ze stosu [tez referencja bo bedziemy usuwac a co za tym idzie zmieniac polozenie naszego wskaznika ]
{
    if (top == nullptr) //jakbysmy chcieli zrobic cos glupiego [zabezpieczenie]
    {
        cout << "Stos jest pusty, wiec nie mozemy nic z niego sciagnac";
        return;
    }
    cout << top->produkt << endl; //wypiszemy go sobie zeby sprawdzic
    stos* robotaju = top;   //roboczy
    top = top->next;    //przypisujemy nasz wskaznik na kolejny element bo ten bedzie usuniety
    delete robotaju; //usuwamy ten z samej gory
}
int main()
{
    cout << "Stos dla artykulow spozywczych" << endl;
    stos* top = new stos;
    sprawdz(top); //sprawdzamy na starcie (teraz bedzie na starcie puste)
    cout << "----------- dodajemy lementy ------------" << endl;    
    push(top, "Maka");  //dodajemy elementy na gore stosu
    push(top, "Cukier");
    push(top, "Banany");
    push(top, "Szyneczka");
    push(top, "Monsterek");
    sprawdz(top);   //sprawdzamy po dodaniu ( teraz nie bedzie puste)
    cout << "sprawdzamy je (sciagamy 3 pierwsze elementy) " << endl; // tego nie bylo w zadaniu ale przetestujmy!
    pop(top); //sciagamy pierwszy z gory
    pop(top);
    pop(top);
    cout << "------------------";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
