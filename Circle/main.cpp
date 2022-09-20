#include "circle.h"
#include <iostream>
using namespace std;

int main()
{

    int r1;
    cout << "----------------------------\n";
    cout << "        Class Cricle" << endl;
    cout << "----------------------------\n";
    cout << "Enter Radius Circle A:";cin >> r1;

    // object A
    Circle a;
    a.set_radius(r1);
    a.cal_area();
    // object B
    Circle b(a); //Default Copy Constructor from object A
    // object C
    Circle c(7);
    c.cal_area();
    // object D
    Circle d;
    d.cal_area_obj(a,c);
    // object E
    Circle e(b); //Default Copy Constuctor from object B
    e = e.ret_area_obj(c);

    //result
    cout << "Circle (A) Radius: "<<a.get_radius()<<" Area = "<<a.get_area()<<endl;
    cout << "Circle (B) Radius: "<<b.get_radius()<<" Area = "<<b.get_area()<<endl;
    cout << "Circle (C) Radius: "<<c.get_radius()<<" Area = "<<c.get_area()<<endl;
    cout << "Circle (D) Radius: "<<d.get_radius()<<" Area = "<<d.get_area()<<endl;
    cout << "Circle (E) Radius: "<<e.get_radius()<<" Area = "<<e.get_area()<<endl;
    return 0;
}

