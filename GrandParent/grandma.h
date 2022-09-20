#ifndef GRANDMA_H
#define GRANDMA_H
#include <iostream>
#include <cstring>

using namespace std;

class GrandMa
{
protected:
    string fname;
    char blood_group;
    int thai_percent;
public:
    GrandMa();
    void set_info();
    void get_info();
};

#endif // GRANDMA_H
