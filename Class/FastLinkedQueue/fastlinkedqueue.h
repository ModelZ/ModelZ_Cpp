#ifndef FASTLINKEDQUEUE_H
#define FASTLINKEDQUEUE_H

#include "../ChainNode/chainnode.h"

class FastLinkedQueue
{
private:
    ChainNode *firstNode;
    ChainNode *lastNode;
    int curSize;

public:
    FastLinkedQueue();      //constructor
    ~FastLinkedQueue();     //destructor
    void enQueue(int e);
    void append(int e);
    int deQueue();
    int remove() { return deQueue(); }
    int front();
    int head() { return front(); }
    int rear();
    int back() { return rear(); }
    int size(){return curSize;}
    void clear();
    void display();
    void clrsc();
};

#endif // FASTLINKEDQUEUE_H
