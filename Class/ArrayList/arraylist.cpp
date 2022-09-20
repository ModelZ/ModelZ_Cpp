#include "arraylist.h"
#include "stdlib.h"
#include <iostream>

using namespace std;


ArrayList::ArrayList(int maxSize)
{
    // create array L with max size elements
    // L = (int *)malloc(maxSize * sizeof(int)) //create new arraylist in C
    L = new int[maxSize];  //create new arraylist in C++

    // store maxSize (parameter) to maxSize (in class)
    this->maxSize = maxSize;

    // set curSize to zero
    curSize = 0;
}

ArrayList::~ArrayList()
{
    //destory L
    delete []L;
}

int ArrayList::size()
{
    return curSize;
}

int ArrayList::indexOf(int e)
{
    if(curSize <= 0){
        cerr << "List is empty!\n";
        return -1;
    }


    for(int i=0;i<curSize;i++){
        if(L[i]==e){ //If num in index == e
            return i;
        }
    }
    cerr << "Error: Not have number " << e << " in any index\n";
    return -1;
}

int ArrayList::get(int i)
{
    if(curSize <= 0){ //List is empty
        cerr << "Error: List is empty!\n";
        return -1;
    }

    if(i < 0){
        cerr << "Warning: Index "<< i << " is under lower bound.....\n";
        cerr << "Get index 0 instead\n";
        return L[0];
    }else if(i >= curSize){
        cerr << "Warning: Index "<< i << " is over upper bound.....\n";
        cerr << "Get index "<<curSize-1<<" instead\n";
        return L[curSize-1];
    }
    return L[i];
}

int ArrayList::remove(int i)
{
    if(curSize <= 0){ //List is empty
        cerr << "Error: List is empty!\n";
        return -1;
    }

    int val = L[i];
    if(L[i] == NULL){ //check if L[i] is null
        cerr << "Error: No value in index " << i << endl;
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




    for(int j = i + 1;j<=curSize;j++){ // Shift to left 1- 4
        if(j == curSize)
            L[j-1] = NULL;
        else
            L[j-1] = L[j];
    }

    curSize--; //decrement curSize

    return val;

}

void ArrayList::set(int i, int e)
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
    L[i] = e;
}

void ArrayList::add(int i, int e)
{
    // check if current size is full?
    if(curSize >= maxSize){
        cerr << "Error: List is Full!!!\n";
        return;
    }

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
    // shift right from i to curSize - 1 down to i [cursize -1,......,i]
    for(int j = curSize - 1; j >= i;j--){
        L[j + 1] = L[j];
    }

    // insert e at i index
    L[i] = e;

    // increment curSize
    curSize++;

}

void ArrayList::display()
{
    cout << "L: [ ";

    for (int i = 0;i<maxSize;i++){
        if(i < curSize)
            cout <<L[i];
       else
            cout << " - ";
        if(i != maxSize-1)    cout << " , ";
    }
    cout << " ]\n";


    cout << "maxSize: " << maxSize;
    cout << ", curSize: " << curSize << endl;



}

void ArrayList::clear()
{
    curSize = 0;
}

void ArrayList::clrsc()
{
    system("cls");
}

