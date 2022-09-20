#ifndef MODELMATH_H
#define MODELMATH_H


class ModelMath
{
private:
    float answer,num1,num2;

public:
    class x1x2{public: float x1;float x2;};

public:
    //random math constructor
    ModelMath(int from1 = 1,int to1 = 100,int from2=1,int to2=100);
    //math calculator 2 numbers
    ModelMath(float num1,float num2);
    float plus();
    float minus();
    float multiply();
    float division();
    float power();
    float floorFloat(float number,int pos); //floor float n positions
    float floor2(float number); //floor float 2 positions
    x1x2 quadratic_eq(int A,int B,int C);
    float n1(){return num1;}
    float n2(){return num2;}

    //math game
    bool Gplus();
    bool Gminus();
    bool Gmultiply();
    bool Gdivision();

    //debug
    void showAns();
};

#endif // MODELMATH_H
