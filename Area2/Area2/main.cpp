#include <iostream>
#include <conio.h>
#include "circle2.h"
#include "square.h"
using namespace std;

int main()
{
    Circle2 A[10];
    Square B[10];
    float temp; // temp cin from user
    char a; // char selector y/n
    int n_Circle = 1,n_Square = 1; //counter loop
    bool chk;

    cout << "-------Circle Class---------\n";
    // Circle Class
    do{
        do{
             cout << "Enter Radius Circle ["<<n_Circle<<"] :";cin >> temp;
             chk = A[n_Circle-1].Circle2::set_redius(temp);
        }while(chk);
        A[n_Circle-1].cal_area();
        n_Circle++;
        if(n_Circle <= 10)
        {
            cout << "Enter another Circle (y/n) ? :";a = getch();
            cout << endl;
        }


    }while(a != 'n' && n_Circle <= 10);
    n_Circle--;

    cout << "-------Square Class---------\n";

    // Square Class
    do{
        cout << "Enter Width Of Square ["<<n_Square<<"] :";cin >> temp;
        B[n_Square-1].set_width(temp);
        B[n_Square-1].cal_area();
        n_Square++;
        if(n_Square <=10)
        {
            cout << "Enter another Square (y/n) ? :";a = getch();
            cout << endl;
        }

    }while(a != 'n' && n_Square <= 10);
    n_Square--;

    //Display
    cout << "\n------------Result--------------\n";

    cout << "Number of Circle = " << n_Circle << endl;
    for(int i = 0;i < n_Circle;i++)
        cout << "Circle ["<<i+1<<"] Radius = "<<A[i].get_radius()<<" , Area = "<<A[i].get_area()<<endl;

    cout << "Number of Square = " << n_Square << endl;
    for(int j = 0;j < n_Square;j++)
        cout << "Circle ["<<j+1<<"] Radius = "<<B[j].get_width()<<" , Area = "<<B[j].get_area()<<endl;


    return 0;
}
