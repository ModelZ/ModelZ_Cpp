#include <iostream>
#include "modelmath.h"
using namespace std;

int main()
{
    ModelMath test(1,1000,1,10); //default 1-100
    ModelMath::x1x2 a;
    /*if(test.Gdivision())
        cout << "Correct!\n";
    else
        cout << "Wrong!\n";
    test.showAns();*/
    a = test.quadratic_eq(3,-5,-8);
    cout <<"X1 = "<<a.x1<<endl;
    cout <<"X2 = "<<a.x2<<endl;
    return 0;
}
