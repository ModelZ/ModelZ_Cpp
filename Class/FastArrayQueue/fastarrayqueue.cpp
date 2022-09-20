#include "fastarrayqueue.h"
#include <iostream>

using namespace std;

FastArrayQueue::FastArrayQueue(int maxSize)
{
    this->maxSize = maxSize;
    curSize = 0;
    L = new int[this->maxSize];
    in = 0;
    out = 0;
}

FastArrayQueue::~FastArrayQueue()
{
    delete [ ]L;
}

void FastArrayQueue::enQueue(int e)
{
    //chack full?
    if (curSize >= maxSize)
    {
        cerr << "Error: Queue is full" << endl;
        return;
    }

    //set L at in index to e
    L[in] = e;

    //in ++
    in = (in + 1) % maxSize;

    //curSize ++
    curSize ++;
}

int FastArrayQueue::deQueue()
{
    //check empty
    if(curSize <= 0){
        cerr << "Error: Queue is empty" << endl;
        return -1;
    }

    //delete queue
    int n = L[out];
    L[out] = NULL;
    out = (out + 1)%maxSize;

    //decrease size - 1
    curSize--;

    return n;
}

int FastArrayQueue::front()
{
    // return L at out index
    return L[out];
}

int FastArrayQueue::rear()
{
    //return L at (in - 1) index
    return L[(in - 1 + maxSize)%maxSize];
}

void FastArrayQueue::clear()
{
    curSize = 0;
    in = 0;
    out = 0;
}

void FastArrayQueue::display()
{
    cout << "L: [";
    for (int i = 0; i < curSize; i++){
        if(i < curSize) cout << L[out + i % maxSize]; else cout << "-";
        if(i < curSize - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "curSize: " << curSize
         << ", maxSize: " << maxSize
         << ", in: " << in
         << ", out: " << out << endl;
}

void FastArrayQueue::clsrc()
{
    system("cls");
}
