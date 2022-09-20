#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../ChainNode/chainnode.h"

class LinkedList
{
// data
    ChainNode *firstNode;
    int curSize;

//method
public:
    LinkedList();
    ~LinkedList();

    int size();                 //return current list size
    int indexOf(int e);     //return index of e
    int get(int i);             //return element at i index
    int remove(int i);       //delete element at i index
    void set(int i,int e);    //set e to element at i index
    void add(int i,int e);   //add e to element at i index

    //added method
    int oddCount(); // find how many odd number in linkedlist
    int evenCount(); // find how many even number in linkedlist
    float sum(); //sum all number of linkedlist
    float mean(); //find mean value of linkedlist
    void sort(); //sort all number in linkedlist

    // dev. debug method
    void display(); //display current list status
    void clear(); //re-initialize array list
    void clrsc(); // clear screen

};

#endif // LINKEDLIST_H
