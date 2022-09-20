#ifndef CIRCLE_H
#define CIRCLE_H
#include "area.h"

class Circle : public Area
{
private:
    float radius;
public:
    Circle();
    void set_radius(float radius);
    float get_radius();
    void cal_area();
};

#endif // CIRCLE_H
