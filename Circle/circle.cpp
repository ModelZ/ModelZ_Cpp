#include "circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle()
{
    //set radius and area to 0
    this->radius = 0;
    this->area = 0;
}

Circle::Circle(float radius)
{
    //set radius
    this->radius = radius;
}

Circle::~Circle()
{

}

void Circle::set_radius(float rad)
{
    this->radius = rad;
}

float Circle::get_radius()
{
    if(this->radius == NULL){
        cerr << "Error: radius is empty!\n";
        return -1;
    }
    return this->radius;
}

void Circle::cal_area()
{
    if(radius != NULL){
        this->area = M_PI * pow(this->radius,2);
    }else
        cerr << "Error: radius is empty!\n";
}

float Circle::get_area()
{
    if(this->area == NULL){
        cerr << "Error: area is empty!\n";
        return -1;
    }
    return this->area;
}

void Circle::cal_area_obj(Circle area1, Circle area2)
{
   area = area1.area + area2.area + (2*area1.radius*area2.radius*M_PI) ; //plus 2 area from arguments to area in class
   radius = area1.radius + area2.radius; //plus 2 radius from arguments to radius in class
}

Circle Circle::ret_area_obj(Circle area)
{
    Circle temp;
    temp.radius = this->radius + area.radius;
    temp.cal_area();
    return temp;
}

