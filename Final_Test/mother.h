#ifndef MOTHER_H
#define MOTHER_H
#include <iostream>
#include <string>

using namespace std;

class Mother
{
protected:
    string fname;
    char blood_group;
    float height;
public:
    Mother();
    void set_info(); // set fname,blood_group and height
    void get_info(); // display mother data
};

#endif // MOTHER_H
