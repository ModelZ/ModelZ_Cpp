#include "student.cpp"

using namespace std;

int main()
{
    Student a,b; //create object a,b

    //set name and score and cal_grade method
    a.set_info("ModelZ",81);
    b.set_info("Fam",63);


    //show result
    a.show_info();
    b.show_info();

    return 0;
}

