#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    int ile,wybor;
    float potrzeba=0;
    cout << "Ile piwerek pijemy? : " << endl;
    cin >> ile;



    for(int i=0; i < ile ; i++ )
    {
   system( "cls" );
     cout << "wybierz " << ile <<" piwerko : " <<endl;
     cout << " 1  - Harnas  2.50" << endl;
     cout << " 2  - Zubr  2.19" << endl;
     cout << " 3  - Desperdaos 3.79" << endl;
     cin>>wybor;
   system( "cls" );

        switch( wybor )
        {
case 1:

    potrzeba+= 2.50;
    break;

case 2:

    potrzeba+= 2.19;
    break;
case 3:

    potrzeba+= 3.79;
    break;
        }
    }
    cout << " to bedzie cie polaku kosztowac : " << potrzeba <<"zloty" ;

    return 0;
}
