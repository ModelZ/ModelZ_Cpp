#include "father.h"
#include <iostream>

using namespace std;

Father::Father()
{

}

void Father::set_info()
{
    cout << "Enter Father first name :";cin >> fname;
    cout << "Enter Father last name :";cin >> lname;
    cout << "Enter Height (cm) :";cin >> height;
}

void Father::get_info()
{
    cout << "Father name: "<<fname<<" "<<lname<<endl;
    cout << "Height: "<<height<<" cm\n";
}
