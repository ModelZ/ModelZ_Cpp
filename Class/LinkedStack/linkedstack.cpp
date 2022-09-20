#include "linkedstack.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

LinkedStack::LinkedStack()
{
    //nothing
}

void LinkedStack::push(int e)
{
    this->add(0,e);
}

int LinkedStack::pop()
{
    return remove(0);
}

int LinkedStack::top()
{
    return get(0);
}

bool LinkedStack::isEmpty()
{
    return (size() <= 0);
}

bool LinkedStack::isFull()
{
    return false;
}

void LinkedStack::swapTopTwo()
{
    if(size() < 2){
        cerr << "Error: Current Size is below 2\n";
        return;
    }
    add(0,remove(1));
}

void LinkedStack::addTopTwo()
{
    addTop(2);
}

void LinkedStack::addTop(int n)
{
    if(size() < n){ //if stack size is not enough
        n = size();
        cerr << "Warning: Stack size is not enough\n";
    }

    int temp = 0;
    for(int i = n-1;i>=0;i--){
        temp += remove(i);
    }
    push(temp);
}

string LinkedStack::infixToPostfix(string infix)
{
  /*  if(!isEmpty())
        this->clear(); //clear stack*/

    string postfix,o;
    char *ch = &infix[0];
    while(*ch != '\0'){

        if(isOperand(*ch))//if is operand?
        {

            if(isEmpty())// if is Empty?
            {
                this->push(*ch);
                //this->display();
            }
            else

            {

               if(*ch == ')'){
                        int index = (indexOf('(')+1);
                        for(int i=1;i<=index;i++){
                            string o = int_to_operator(this->pop());
                            if(i != index)
                            postfix += o;

                        }
                        //this->display();
               }else

                if(*ch == '('){
                    this->push(*ch);
                  //  this->display();
                }else

                if(checkOrderOperator(*ch,this->peek()) == 3){
                    this->push(*ch);
                    //this->display();
                }else if(checkOrderOperator(*ch,this->peek()) == 1)
                {
                    postfix += int_to_operator(this->pop());
                    if(checkOrderOperator(*ch,this->peek()) == 1){
                        postfix += int_to_operator(this->pop());
                        //this->display();
                    }
                    this->push(*ch);
                //    this->display();
                }
                else
                {

                   postfix += int_to_operator(this->pop());
                   this->push(*ch);
                  // this->display();
                }

            }


        }else{
            postfix += *ch;
            //this->display();
        }

        if(this->isOperand(*ch) && *ch != ')' && *ch != '(' )
            postfix += " ";
        ch++;
        //cout << postfix<<endl;


    }
    // pop all
    for(int j = 0;j < this->size()+1;j++){
        postfix += int_to_operator(this->pop());
    }
    //this->display();
    return postfix;
}

float LinkedStack::executePostfix(string postfix)
{
    float result = 0;
    float *fpOperand = new float[2];
    int *ipOperand = (int *)fpOperand;
    // scan each character in postfix from left to right
    for(int i=0;i<(int)postfix.length();i++)
    {
        // check character postfix[i]
        switch (postfix[i]) {
        case ' ': //Do nothing
            break;
        // operator: pop two, do operation, push back to stack
        case '+':
            ipOperand[1] = pop(); //pop top two
            ipOperand[0] = pop();
            fpOperand[0] += fpOperand[1]; //addition
            push(ipOperand[0]); //push
            break;
        case '-':
            ipOperand[1] = pop(); //pop top two
            ipOperand[0] = pop();
            fpOperand[0] -= fpOperand[1]; //subtraction
            push(ipOperand[0]); //push
            break;
        case '*':
            ipOperand[1] = pop(); //pop top two
            ipOperand[0] = pop();
            fpOperand[0] *= fpOperand[1]; //multipication
            push(ipOperand[0]); //push
            break;
        case '/':
            ipOperand[1] = pop(); //pop top two
            ipOperand[0] = pop();
            fpOperand[0] /= fpOperand[1]; //division
            push(ipOperand[0]); //push
            break;
        case '^':
            ipOperand[1] = pop(); //pop top two
            ipOperand[0] = pop();
            fpOperand[0] = pow(fpOperand[0],fpOperand[1]); //exponentiation
            push(ipOperand[0]); //push
            break;



             // operand: push to stack
        default:
            fpOperand[0] = postfix[i] - '0'; //convert char to int
            push(ipOperand[0]);
        }
     }

    // pop final result
    ipOperand[0] = pop();
    result = fpOperand[0];
    //free mem
    delete []fpOperand;

    // return result
    return result;
}

bool LinkedStack::isOperand(char ch)
{
    return (ch == '+'||ch == '-'||ch == '*'||ch == '/'||ch == '^'||ch == '('||ch == ')');
}

int LinkedStack::checkOrderOperator(char operator1, char operator2)
{
    if(operator2 == '(' || operator2 == ')'){
        return 3;
    }

    int o1,o2;
    switch (operator1) {
        case '+': case '-':o1 = 1;break;
        case '*': case '/':o1 = 2;break;
        default:o1=3;
    }
    switch (operator2) {
        case '+': case '-':o2 = 1;break;
        case '*': case '/':o2 = 2;break;
        default:o2=3;
    }
    if(o1==o2)return 2;else if(o1>o2)return 3;else return 1;

}

string LinkedStack::int_to_operator(int number)
{
    switch (number) {
        case '+': return " +";break;
        case '-': return " -";break;
        case '*': return " *";break;
        case '/': return " /";break;
        case '^': return " ^";break;
    }
}
