#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define DEFAULT_LIST_SIZE 5

class ArrayList
{
//data (variables)
private:
    int *L;                   //list array
    int maxSize;         // maximum size
    int curSize;           //current list size



//method (functions)
public:
    ArrayList(int maxSize = DEFAULT_LIST_SIZE);      //Constructor (Preparation for using class)
    ~ArrayList();                                                           //Destructor ()

    int size();                 //return current list size
    int indexOf(int e);     //return index of e
    int get(int i);             //return element at i index
    int remove(int i);       //delete element at i index
    void set(int i,int e);    //set e to element at i index
    void add(int i,int e);   //add e to element at i index


    // dev. debug method
    void display(); //display current list status
    void clear(); //re-initialize array list
    void clrsc(); // clear screen

};

#endif // ARRAYLIST_H
