#include "grandfa.h"
#include <iostream>


GrandFa::GrandFa()
{

}

void GrandFa::set_info()
{
    cout << "Enter Grandfather first name: "; cin >> fname;
    cout << "Enter Grandfather last name: "; cin >> lname;
    cout << "Enter Percent of Thai nationality 25,50,75,100 (%) :"; cin >> thai_percent;
}

void GrandFa::get_info()
{
    cout << "Grandfather name : "<< fname<<" "<<lname<<endl;
    cout << "Thai nationality : "<<thai_percent<<" %\n";
}
