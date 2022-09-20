#ifndef SORTING_H
#define SORTING_H
#include "../ArrayList/arraylist.h" //Header
#include <iostream>
#include <ctime> //time
#define DEFAULT_SIZE 16

using namespace std;

class Sorting
{
//data members
private:
    ArrayList *data; //data for sorting
    ArrayList *temp; //backup data
    clock_t begin = 0,end = 0;
    int maxSize;

    //measure
    int swapCounter;
    int loopCounter;
    double timeElasped;

// method members
public:
    Sorting(int maxSize = DEFAULT_SIZE); // constructor
    ~Sorting(); //destructor

    // auxilary function
    void random(); //generate random data
    void backup(); //copy from data to temp
    void restore(); //copy back from temp to data
    void display(); //display data
    void displayTimeElasped(); //display sorting time
    void displayLoopCounter(); //display loop counter
    void displaySwapCounter(); //display swap counter
    void line(){cout<<"-----------------------------------------------------------------------\n";}
    void startEffTest(); // Start Efficiency Test
    void endEffTest(); // End Efficiency Test
    void sixEfficiencySortingComparison(int n); // compare 6 sorting
    void clear();

    //sorting algorithm (call by user)
    void selection(bool detail = false); //selection sort
    void insertion(bool detail = false); //insertion sort
    void bubble(bool detail = false); //bubble sort
    void shell(bool detail = false); //shell sort
    void merge(); //merge sort
    void quick(); //quick sort

// method support sorting (call by class)
private:
    void swap(int i,int j);

    int findMaxIndex(int n);
    void insert(int n);
    void bubble_(int n);

    //quick sort
    void quick_(int begin,int end);
    int pickPivotIndex(int begin,int end);

    //shell sort
    void selectK(int k);
    int findMinIndexK(int iStart,int k);

    //merge sort
    void copyArray(ArrayList *src,ArrayList*desc,int begin,int end);
    void merge_(ArrayList *result,int begin,int end);
};

#endif // SORTING_H
