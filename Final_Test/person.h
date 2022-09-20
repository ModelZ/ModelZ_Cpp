#ifndef PERSON_H
#define PERSON_H
#include "father.h"
#include "mother.h"
#include <iostream>
#include <string>

using namespace std;

class Person : public Father , public Mother
{
private:
    string name;
    string sex;
    float height;
public:
    Person();
    void set_info(); //(father + mother) inherit setting + person
    void get_info(); //display family info
    void height_cal(); //(father+mother)/2 height
};

#endif // PERSON_H
