#include <iostream>

using namespace std;

int main()
{
    int alfa;
    cout << "Cwiartka kata" << endl;
    cout << "Podaj kat alfa w stopniach: ";
    cin>>alfa;

    while(alfa>360) alfa-=360;

    switch( alfa>90 )
    {
        case true:
        switch(alfa>180)
        {
            case true:
            switch(alfa>270)
            {
                case true:
                cout<< "IV cwiartka";
                return 0;
                case false:
                cout<< "III cwiartka";
                return 0;
            }
            case false:
            cout<<"II cwiartka ";
            return 0;
        }
    case false:
    cout<<"I cwiartka ";
    return 0;
    }
    return 0;
}
