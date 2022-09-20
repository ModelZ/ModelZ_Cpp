#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
private:
    string name;
    float score;
    char grade;

public:

    void set_info(string name,float score); //add name and score
    void cal_grade(float score); //calculate grade from score
    void show_info(); //show name,grade,score
};

#endif // STUDENT_H
