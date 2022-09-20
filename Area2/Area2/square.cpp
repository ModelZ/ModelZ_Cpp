#include "square.h"
#include <cmath>

Square::Square()
{

}

float Square::get_width()
{
    return width;
}

void Square::set_width(float width)
{
    this->width = width;
}

void Square::cal_area()
{
    area = pow(width,2);
}

