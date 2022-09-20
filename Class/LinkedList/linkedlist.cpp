#include "linkedlist.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    curSize = 0;
    firstNode = new ChainNode();
}

LinkedList::~LinkedList()
{
    ChainNode *p = firstNode;
    while (p){
        ChainNode *n = p->next;
        delete p;
        p = n;
    }
}

int LinkedList::size()
{
    return curSize;
}

int LinkedList::indexOf(int e)
{
    //list is empty
    if(curSize <= 0){
        cerr << "List is empty!\n";
        return -1;
    }

    //set p pointing to e0 node
    ChainNode *p = firstNode->next;
    for(int i = 0;i<curSize;i++){
        if(p->element == e){
            return i;
        }
        // move p to next node
        p = p->next;
    }
    cerr << "Error: Not have number " << e << " in any index\n";
    return -1;
}

int LinkedList::get(int i)
{
    if(curSize <= 0){ //List is empty
        cerr << "Error: List is empty!\n";
        return -1;
    }

    //create p pointing to e0
    ChainNode *p = firstNode->next;


    if(i < 0){
        cerr << "Warning: Index "<< i << " is under lower bound.....\n";
        cerr << "Get index 0 instead\n";
        return p->element; //return element of index 0
    }else if(i >= curSize){
        cerr << "Warning: Index "<< i << " is over upper bound.....\n";
        cerr << "Get index "<<curSize-1<<" instead\n";
        //move p to target index
        for(int j=1;j<=curSize-1;j++)
            p = p->next;
        //return element of target index
        return p->element;
    }
    //move p to target index
    for(int k=1;k<=i;k++)
        p = p->next;
    //return element of target index
    return p->element;
}

int LinkedList::remove(int i)
{

    if(curSize <= 0){ //List is empty
        cerr << "Error: List is empty!\n";
        return -1;
    }

    if(i < 0){ // check lower upper bound index
        cerr << "Error: Index "<< i << " is under lower bound.....\n";
        cerr << "Error: Cannot remove...\n";
        return -1;
    }else if(i >= curSize){
        cerr << "Error: Index "<< i << " is over upper bound.....\n";
        cerr << "Error: Cannot remove...\n";
        return -1;
    }

    // set p pointing to dummy
    ChainNode *p = firstNode;

    //move p forward for i times
    for(int j=1;j<=i;j++)
        p = p->next;

    //set q pointing to next node of p
    ChainNode *q = p->next;

    //set r pointing to next node of q
    ChainNode *r = q->next;

    //keep q->element to temp
    int temp = q->element;

    //delete node q
    delete q;

    // adjust link
    p->next = r;

    curSize--; //decrement curSize

    return temp;
}

void LinkedList::set(int i, int e)
{
    if(curSize == 0){
        cerr << "Error: List is empty!!\n";
        return;
    }else

    if(i < 0){
        cerr << "Error: Index "<< i << " is under lower bound.....\n";
        cerr << "Error: Cannot Set!\n";
        return;
    }else if(i >= curSize){
        cerr << "Error: Index "<< i << " is over upper bound.....\n";
        cerr << "Error: Cannot Set!\n";
        return;
    }

    //create p pointing to dummy
    ChainNode *p = firstNode;
    //move p pointing to index i
    for(int j=1;j<=i+1;j++)
        p = p->next;
    //set new element of i
    p->element = e;

}

void LinkedList::add(int i, int e)
{

    //index accepted [0,1,2,...,curSize]
    //check index [lower bound] error
    if(i < 0){
        cerr << "Warning: Index "<< i << " is under lower bound.....\n";
        cerr << "Add the lowest bound instead\n";
        i = 0;
    }else if(i > curSize){ //check index [upper bound] error

        cerr << "Warning: Index "<< i << " is over upper bound.....\n";
        cerr << "Add the highest bound instead\n";
        i = curSize;

    }

    // index is correct position

    //set p pointing to dummy
    ChainNode *p = firstNode;

    //move p forward for i time
    for(int j=1;j<=i;j++)
        p = p->next;
    //create new node
    ChainNode *q = new ChainNode(e,p->next);
    if(!q){
        cerr << "Error: Memory is full!\n";
        return;
    }

    //adjust link
    p->next = q;

    // increment curSize
    curSize++;

}

int LinkedList::oddCount()
{
    //set p pointing to dummy
    ChainNode *p = firstNode;
    int count=0;
    //loop all numbers in linkedlist
    for(int i=1;i<=curSize;i++){
        p = p->next;
        if(p->element%2==1)
            count++;
    }
    return count;
}

int LinkedList::evenCount()
{
    //set p pointing to dummy
    ChainNode *p = firstNode;
    int count=0;
    //loop all numbers in linkedlist
    for(int i=1;i<=curSize;i++){
        p = p->next;
        if(p->element%2==0)
            count++;
    }
    return count;
}

float LinkedList::sum()
{
    //set p pointing to dummy
    ChainNode *p = firstNode;
    float sum=0;
    //loop all numbers in linkedlist
    for(int i=1;i<=curSize;i++){
        p = p->next;
        sum += p->element;
    }
    return sum;
}

float LinkedList::mean()
{
    return this->sum()/(float)this->curSize;
}

void LinkedList::sort()
{
    //set p pointing C0
    ChainNode *p = firstNode->next;
    //set q pointing next to C0
    ChainNode *q = p->next;
    int temp;

    for(int i=1;i<=curSize;i++){
        for(int j=i+1;j<=curSize;j++){
            if(p->element > q->element){
                temp = p->element;
                p->element = q->element;
                q->element = temp;
            }
            q = q->next;
            p = p->next;
       }
        p = firstNode->next;
        q = p->next;
    }

}

void LinkedList::display()
{
    cout << "L: [ ";

    ChainNode *p = firstNode->next;
    while(p){
        //display element
        cout << p->element;

        //display separater
        if(p->next)
            cout << ", ";

        //move to next element
        p = p->next;
    }

    cout << " ]\n";
    cout << " curSize: " << curSize << endl;

}

void LinkedList::clear()
{
    //check list is already empty
    if(curSize == 0){
        cerr << "Error: Your list is already empty!\n";
        return;
    }


    //create p pointing to e0
    ChainNode *p = firstNode->next;
    //create q pointing to next node of e0;
    ChainNode *q = p->next;
    //set dummy to NULL
    firstNode->next = NULL;

    //delete process
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    //set curSize to 0
    curSize = 0;
    //msg
    cout << "List Cleared!\n";
}

void LinkedList::clrsc()
{
    system("cls");
}

