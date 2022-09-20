#include <iostream>
#include <conio.h>
#include "fama.h"
using namespace std;

int main()
{

    FaMa fama[10];
    int r1=1;
    char ch;

    // Input Process
    cout << "**** Enter Information ****";
    do{

        cout << "\n\nPerson : "<<r1<<endl;
        fama[r1-1].set_info();


    if(r1 < 10) {cout << "Enter another Father or Mother (y/n) :";ch = getch();}
        r1++;
    }while (r1 <= 10 && ch == 'y');
    r1--;

    //Output Process
    cout << "\n\n**** Display Information ****\n";
    for(int i=0;i<r1;i++){

        cout << "\nPerson : "<<i+1<<endl;
        fama[i].get_info();
    }

    return 0;
}
