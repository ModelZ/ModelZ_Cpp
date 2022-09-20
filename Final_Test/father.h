#ifndef FATHER_H
#define FATHER_H
#include <iostream>
#include <string>

using namespace std;

class Father
{
protected:
    string fname;
    string lname;
    float height;
public:
    Father();
    void set_info(); // set fname,lname and height
    void get_info(); // display father data
};

#endif // FATHER_H
