#include <iostream>
#include <conio.h>
#include "person.h"
using namespace std;

int main()
{
    Person Per[5];
    char ch;
    int i,j;

    cout << "****Enter Information ****";

    // INPUT

    for(i=0;i<5;i++)
    {
        cout << "\n\nPerson : "<<i+1<<endl;
        Per[i].set_info();

        cout << "Enter another person (y/n):";ch = getch();
        if(ch == 'n') break;
    }

    //OUTPUT

    cout << "\n\n****Display Information ****";

    for(j = 0;j<i+1;j++)
    {
        cout << "\n\n----------------\n";
        cout << "    Person : "<<j+1<<endl;
        cout << "***************\n";

        Per[j].get_info();

    }

    return 0;
}
