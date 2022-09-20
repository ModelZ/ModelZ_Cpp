#include <iostream>
#include <conio.h>
#include "circle.h"
#include "square.h"

using namespace std;

int main()
{
    int cir,sq,n_cir=0,n_sq=0;
    char a;

    //Create Array Of Object
    Circle cirA[10];
    Square squB[10];

    //Class Circle
    do{
        cout << "Enter Radius Circle["<<n_cir+1<<"] :";cin>>cir;
        cirA[n_cir].set_radius(cir);
        cirA[n_cir].cal_area();
        n_cir++;

        cout << "Enter Another Circle (y/n)?:";a = getch();
        cout << endl;
    }while(n_cir<10&&a != 'n');

    cout << endl;

    //Class Square
    do{
        cout << "Enter Width of Square["<<n_sq+1<<"] :";cin>>sq;
        squB[n_sq].set_width(sq);
        squB[n_sq].cal_area();
        n_sq++;

        cout << "Enter Another Square (y/n)?:";a = getch();
        cout << endl;
    }while(n_sq<10&& a != 'n');

    cout << "\n----------------------\n";
    //Display Circle
    cout << "Number Of Circle = "<<n_cir<<endl;
    for(int i = 0;i<n_cir;i++){
        cout << "Circle["<<i+1<<"] Radius = "<<cirA[i].get_radius()<<" ,Area = "<< cirA[i].get_area()<<endl;
    }
    cout << "----------------------\n";
    //Display Square
    cout << "Number Of Square = "<<n_sq<<endl;
    for(int j = 0;j<n_sq;j++){
        cout << "Square["<<j+1<<"] Width = "<<squB[j].get_width()<<" ,Area = "<< squB[j].square_get_area()<<endl;
    }
    return 0;
}

