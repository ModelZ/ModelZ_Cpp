#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <../ArrayList/arraylist.h>

#define DEFAULT_STACK_SIZE 5

class ArrayStack : public ArrayList
{
private:
    int maxSize;

public:
    ArrayStack(int maxSize = DEFAULT_STACK_SIZE);

    void push(int e);
    int pop();
    int top();
    int peek(){return top();}
    bool isEmpty();
    bool isFull();
    void stackClear();

};

#endif // ARRAYSTACK_H
