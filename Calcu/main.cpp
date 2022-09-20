#include <iostream>

using namespace std;

//Function Declaration
void line();
void summ(float a,float b);
void minuss(float a,float b);
void multiply(float a,float b);
void division(float a,float b);

//Main Function
int main()
{
    //Variable Declaration
    float num1,num2;


    line();
    cout << "           Normal Calculator" << endl;
    line();

    cout << "Function +,-,x,/\n"
            << "Enter your number 1 :";
    cin >> num1;
    cout << "Enter your number 2 :";
    cin >> num2;
    line();
    summ(num1,num2);
    line();
    minuss(num1,num2);
    line();
    multiply(num1,num2);
    line();
    division(num1,num2);
    line();

    return 0;
}



//Function Section

void line(){
    cout << "****************************************\n";
}
void summ(float a,float b){
    cout << "Summation : " << a <<" + "<<b<<" = "<<a+b<<endl;
}
void minuss(float a,float b){
    cout << "Subtraction : " << a <<" - "<<b<<" = "<<a-b<<endl;
}
void multiply(float a,float b){
    cout << "Multiplication : " << a <<" * "<<b<<" = "<<a*b<<endl;
}
void division(float a,float b){
    if(b==0)
        cout << "Division : "<< a <<" / "<<b<<" = Undefined\n";
    else
        cout << "Division : " << a <<" / "<<b<<" = "<<a/b<<endl;
}

