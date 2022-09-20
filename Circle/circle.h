#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
private:
    float radius,area;

public:
    Circle(); //constuctor 1
    Circle(float radius); //constuctor 2
    ~Circle();

    void set_radius(float rad);
    float get_radius();
    void cal_area();
    float get_area();
    void cal_area_obj(Circle area1,Circle area2);
    Circle ret_area_obj(Circle area);
};

#endif // CIRCLE_H
