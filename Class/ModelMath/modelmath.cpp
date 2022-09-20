#include "modelmath.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

ModelMath::ModelMath(int from1,int to1,int from2,int to2)
{
    /* initialize random seed: */
      srand (time(NULL));
   // random number
   num1 = (rand()%(to1+1))+(from1);
   num2 = (rand()%(to2+1))+(from2);

}

ModelMath::ModelMath(float num1, float num2)
{
  this->num1 = num1;
  this->num2 = num2;
}

float ModelMath::plus()
{
    return num1+num2;
}

float ModelMath::minus()
{
    return num1-num2;
}

float ModelMath::multiply()
{
    return num1*num2;
}

float ModelMath::division()
{
    return num1/num2;
}

float ModelMath::power()
{
    return pow(num1,num2);
}

float ModelMath::floorFloat(float number,int pos)
{
    return (floor(number*pow(10,pos)+0.5))/pow(10,pos);
}

float ModelMath::floor2(float number)
{
    return floorFloat(number,2);
}

ModelMath::x1x2 ModelMath::quadratic_eq(int A, int B, int C)
{
    x1x2 a;
    a.x1 = (-B + sqrt(pow(B,2)-(4*A*C)))/(2*A);
    a.x2 = (-B - sqrt(pow(B,2)-(4*A*C)))/(2*A);
    return a;
}
bool ModelMath::Gplus()
{
    answer = plus();

    float userans;
    cout << "----------------------\n";
    cout << this->num1 << " + "<<this->num2<<" = ?\n";
    cout << "Ans:";cin >> userans;



    if(userans == this->answer)
        return true;
    else
        return false;
}

bool ModelMath::Gminus()
{
    answer = minus();

    float userans;
    cout << "----------------------\n";
    cout << this->num1 << " - "<<this->num2<<" = ?\n";
    cout << "Ans:";cin >> userans;



    if(userans == this->answer)
        return true;
    else
        return false;
}

bool ModelMath::Gmultiply()
{
    answer = multiply();

    float userans;
    cout << "----------------------\n";
    cout << this->num1 << " x "<<this->num2<<" = ?\n";
    cout << "Ans:";cin >> userans;



    if(userans == this->answer)
        return true;
    else
        return false;
}

bool ModelMath::Gdivision()
{
    float userans;
    cout << "----------------------\n";
    cout << this->num1 << " / "<<this->num2<<" = ?\n";
    cout << "Ans:";cin >> userans;

    answer = floor2(division());

    if(userans == answer)
        return true;
    else
        return false;
}

void ModelMath::showAns()
{
    cout << this->answer<<endl;
}
