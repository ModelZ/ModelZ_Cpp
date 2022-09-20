#include "mother.h"

Mother::Mother()
{

}

void Mother::set_info()
{
    cout << "Enter Mother first name :";cin >> fname;
    cout << "Enter Blood type :";cin >> blood_group;
    cout << "Enter Height (cm) :";cin >> height;
}

void Mother::get_info()
{
    cout << "Mother name: "<<fname<<endl;
    cout << "Blood type: "<<blood_group<<endl;
    cout << "Height: "<<height<<" cm\n";
}
