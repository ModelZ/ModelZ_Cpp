#include "grandma.h"

GrandMa::GrandMa()
{

}

void GrandMa::set_info()
{
    cout << "Enter Grandmother first name: "; cin >> fname;
    cout << "Enter Blood type: "; cin >> blood_group;
    cout << "Enter Percent of Thai nationality 25,50,75,100 (%) :"; cin >> thai_percent;
}

void GrandMa::get_info()
{
    cout << "Grandmother name : "<<fname<<endl;
    cout << "Blood type : "<<blood_group<<endl;
    cout << "Thai nationality : "<<thai_percent<<"%\n";
}
