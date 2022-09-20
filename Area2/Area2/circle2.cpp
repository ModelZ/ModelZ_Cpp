#include "circle2.h"
#include <iostream>
using namespace std;

Circle2::Circle2()
{

}

bool Circle2::set_redius(float radius)
{
    // if radius within 1-99 loop again
    if(radius > 99 || radius < 0)
    {
        cout << "Radius out of range 0-99, Enter radius again.\n";
        return true;
    }

    //overriding member function
    Circle::set_radius(radius);
    return false;
}
