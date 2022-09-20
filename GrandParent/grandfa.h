#ifndef GRANDFA_H
#define GRANDFA_H
#include <iostream>
#include <cstring>

using namespace std;

class GrandFa
{
protected:
    string fname;
    string lname;
    int thai_percent;

public:
    GrandFa();
    void set_info();
    void get_info();
};

#endif // GRANDFA_H
