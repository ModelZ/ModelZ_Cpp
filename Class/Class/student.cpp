#include <iostream>
#include "student.h"

using namespace std;


void Student::set_info(string name, float score)
{
    this->name = name; //add name
    this->score = score; //add score
    cal_grade(this->score);
}

void Student::cal_grade(float score)
{
    if(score >= 80)
        this->grade = 'A';
    else if(score >= 70)
        this->grade = 'B';
    else if(score >= 60)
        this->grade = 'C';
    else if(score >= 50)
        this->grade = 'D';
    else
        this->grade = 'F';
}

void Student::show_info()
{
    cout << "Student -> name: "<< this->name <<"   Score: "<<this->score<<"   Grade: "<<this->grade<<endl;
}
