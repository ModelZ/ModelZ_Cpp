#ifndef FAMA_H
#define FAMA_H
#include "grandfa.h"
#include "grandma.h"
#include <iostream>
#include <cstring>

using namespace std;

class FaMa : private GrandFa,private GrandMa
{
private:
    string name;
    string sex;
    int thai_percent;
public:
    FaMa();
    void thai_cal();
    void set_info();
    void get_info();
};

#endif // FAMA_H
