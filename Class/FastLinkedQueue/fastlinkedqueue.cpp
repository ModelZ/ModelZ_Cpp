#include "fastlinkedqueue.h"
#include <iostream>

using namespace std;

FastLinkedQueue::FastLinkedQueue()
{
    firstNode = new ChainNode();
    lastNode = firstNode;
    curSize = 0;
}

FastLinkedQueue::~FastLinkedQueue()
{
    // p point to dummy
    ChainNode *p = firstNode;

    // iterative remove
    while (p != NULL) {
        ChainNode *n = p->next;
        delete p;
        p = n;
    }
}

void FastLinkedQueue::enQueue(int e)
{
    // create new node
    ChainNode *p = new ChainNode(e);
    // chechk mem
    if(p == NULL){
        cerr << "Error: Memory is full\n";
        return;
    }
    // adjust link
    lastNode->next = p;
    //move lastNode forward
    lastNode = p;

    //increase curSize + 1
    curSize++;
}

int FastLinkedQueue::deQueue()
{
    //check empty
    if(curSize <=0){
        cerr << "Error: Queue is Empty!\n";
        return -1;
    }

    // p point to e0
    ChainNode *p = firstNode->next;
    // next of dummy point to p.next
    firstNode->next = p->next;
    int n = p->element;
    //remove p
    delete p;
    //decrease curSize - 1
    curSize--;

    return n;
}

int FastLinkedQueue::front()
{
    //check empty
    if(curSize <=0){
        cerr << "Error: Queue is Empty!\n";
        return -1;
    }
    return firstNode->next->element;
}

int FastLinkedQueue::rear()
{
    //check empty
    if(curSize <=0){
        cerr << "Error: Queue is Empty!\n";
        return -1;
    }
    return lastNode->element;
}

void FastLinkedQueue::clear()
{
    ChainNode *p = firstNode->next;
    //lastNode to dummy
    lastNode = firstNode;

    //remove only elements (exclude dummy)
    while (p != NULL) {
        ChainNode *q = p->next;
        delete p;
        p = q;
    }
    //set dummy.next to NULL
    firstNode->next = NULL;
    //set curSize = 0
    curSize = 0;

}

void FastLinkedQueue::display()
{
    cout << "L: [";
    // p point to e0
    ChainNode *p = firstNode->next;

    // iterative display each node
    for (int i = 0; i < curSize; i++){

        cout << p->element;
        p = p->next;
        if(i < curSize - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "curSize: " << curSize <<endl;
}

void FastLinkedQueue::clrsc()
{
        system("cls");
}
