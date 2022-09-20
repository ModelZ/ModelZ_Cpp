#include "fama.h"

FaMa::FaMa()
{

}

void FaMa::thai_cal()
{
    thai_percent = (GrandFa::thai_percent + GrandMa::thai_percent)/2;
}

void FaMa::set_info()
{
    GrandFa::set_info(); cout<<"\n";
    GrandMa::set_info(); cout<<"\n";
    thai_cal();
    cout << "Enter name: ";cin>>name;
    cout << "Enter Sex (Male/Female): ";cin >> sex;
}

void FaMa::get_info()
{
    GrandFa::get_info(); cout<<"\n";
    GrandMa::get_info(); cout<<"\n";
    cout << (sex == "male"?"Father name : ":"Mother name : ") << name << " " <<lname<<endl;
    cout <<"Sex : "<<sex <<endl;
    cout << "Blood type : "<<blood_group<<endl;
    cout << "Thai nationality : "<<thai_percent<<"%\n";

}
