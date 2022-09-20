#include "arraystack.h"

ArrayStack::ArrayStack(int maxSize)
    :ArrayList(maxSize)
{
    this->maxSize = maxSize;
}

void ArrayStack::push(int e)
{
    //push in ArrayStack at tail
    add(size(),e);
}

int ArrayStack::pop()
{
    // pop out ArrayStack at tail
    return remove(size()-1);
}

int ArrayStack::top()
{
    return get(size()-1);
}

bool ArrayStack::isEmpty()
{
    return (size() <= 0);
}

bool ArrayStack::isFull()
{
    //is stack is full?
    return (size() >= maxSize);
}

