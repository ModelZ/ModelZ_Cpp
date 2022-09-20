#include "person.h"

Person::Person()
{

}

void Person::set_info()
{
    Father::set_info();
    cout <<endl;
    Mother::set_info();
    cout <<endl;

    cout << "Enter name :"; cin >> name;
    cout << "Enter Sex (Male/Female) :"; cin >> sex;

}

void Person::get_info()
{
    Father::get_info();
    cout <<endl;
    Mother::get_info();
    cout <<endl;
    height_cal();

    cout << "My name: "<<name<<" "<<lname<<endl;
    cout << "Sex :"<<sex<<endl;
    cout << "Blood type :"<<blood_group<<endl;
    cout << "Height :"<<height<<" cm\n";
}

void Person::height_cal()
{
    this->height = (Mother::height + Father::height) / 2;
}
