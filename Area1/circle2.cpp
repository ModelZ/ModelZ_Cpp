#include "circle2.h"
#include <iostream>
using namespace std;

Circle2::Circle2()
{

}

bool Circle2::set_redius(float radius)
{
    //overriding member function
    Circle::set_radius(radius);
    return false;
}
