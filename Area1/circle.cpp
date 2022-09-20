#include "circle.h"
#include <cmath>

Circle::Circle()
{

}

void Circle::set_radius(float radius)
{
    this->radius = radius;
}

float Circle::get_radius()
{
    return radius;
}

void Circle::cal_area()
{
    area = M_PI * pow(radius,2);
}

