#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <string>
#include "../LinkedList/linkedlist.h"

using namespace std;

class LinkedStack : public LinkedList
{
public:
    LinkedStack();

    void push(int e);
    int pop();
    int top();
    int peek(){return top();}
    bool isEmpty();
    bool isFull();

    void swapTopTwo(); //swap 2 n first stack
    void addTopTwo(); //plus 2 n first stack
    void addTop(int n); //plus all top n first stack

    //advance method
    string infixToPostfix(string infix);
    float executePostfix(string postfix);

    //debug
    bool isOperand(char ch);
    int checkOrderOperator(char operator1,char operator2);
    // 1 is less than 2 is equal 3 is more than
    string int_to_operator(int number);

};

#endif // LINKEDSTACK_H
