#ifndef SQUARE_H
#define SQUARE_H
#include "area.h"

class Square : public Area
{
private:
    float width;
public:
    Square();
    float get_width();
    void set_width(float width);
    void cal_area();
};

#endif // SQUARE_H
