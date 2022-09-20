#include "sorting.h"
#include <ctime> //time
#include <iostream> //srand,rand

using namespace std;

Sorting::Sorting(int maxSize)
{
    //store maxsize
    this->maxSize = maxSize;

    //allocate data and temp;
    data = new ArrayList(this->maxSize);
    temp = new ArrayList(this->maxSize);

    // fill all element to zero
 /*   for (int i = 0;i<this->maxSize;i++){
        data->add(data->size(),0);
        temp->add(temp->size(),0);
    }*/

    //set seed by time
    srand(time(NULL));

    //initial measure variables
    swapCounter = 0;
    loopCounter = 0;
    timeElasped = 0.0;
}

Sorting::~Sorting()
{
    delete data;
    delete temp;
}

void Sorting::random()
{
    if(data->size() >= maxSize){
        cerr << "Error: List is Full!\n";
        return;
    }

    for (int i = 0; i < maxSize; i++)
        data->add(i,rand()%100);

}

void Sorting::backup()
{
    // copy from data to temp
    for(int i = 0;i<maxSize;i++)
        if(temp->size() < maxSize)
           temp->add(i,data->get(i));
        else
            temp->set(i,data->get(i));
}

void Sorting::restore()
{
    // copy from temp to data
    for(int i = 0;i<maxSize;i++)
        if(data->size() < maxSize )
        data->add(i,temp->get(i));
    else
        data->set(i,temp->get(i));
}

void Sorting::display()
{
    cout << "data: ";
    for (int i=0;i<maxSize;i++)
        printf("%2d%c",data->get(i),i == maxSize - 1?'\n':',');
}

void Sorting::displayTimeElasped()
{
    printf("time: %0.9f seconds\n", timeElasped);
}

void Sorting::displayLoopCounter()
{
    cout << "loop: "<<loopCounter<<" times"<<endl;
}

void Sorting::displaySwapCounter()
{
    cout << "swap: "<<swapCounter<< " times"<<endl;
}

void Sorting::startEffTest()
{
    // clear timer and counter
    swapCounter = 0;
    loopCounter = 0;
    begin = clock();
}

void Sorting::endEffTest()
{

    //done time
    end = clock();
    timeElasped = double(end - begin) / double(CLOCKS_PER_SEC);

    //display efficiency
    line();
    displaySwapCounter();
    displayLoopCounter();
    displayTimeElasped();
    line();
}

void Sorting::sixEfficiencySortingComparison(int n)
{
    Sorting Tester(10000);
    cout << "--------------SixEfficiencySortingComparison---------------\n";
    Tester.random();
    cout << "Number Of Data:"<<Tester.maxSize<<endl;
    Tester.backup();
    Tester.line();
    cout << "\n---1.Selection Sorting\nRaw";
    Tester.selection();
    Tester.restore();
    cout << endl;
    cout << "---2.Insertion Sorting\nRaw";
    Tester.insertion();
    Tester.restore();
    cout << endl;
    cout << "---3.Bubble Sorting\nRaw";
    Tester.bubble();
    Tester.restore();
    cout << endl;
    cout << "---4.Shell Sorting\nRaw";
    Tester.shell();
    Tester.restore();
    cout << endl;
    cout << "---5.Merge Sorting\nRaw";
    Tester.merge();
    Tester.restore();
    cout << endl;
    cout << "---6.Quick Sorting\nRaw";
    Tester.quick();
    Tester.restore();
    cout << endl;

}

void Sorting::clear()
{
    data->clear();
}

void Sorting::selection(bool detail)
{

    startEffTest();

    //set num of elm
    for (int nElement = maxSize; nElement > 1;nElement --){
        //find max index
        int maxIndex = findMaxIndex(nElement);

        //swap value at maxindex
        swap(maxIndex, nElement -1);

        //check detail process
        if(detail) display();
    }

    endEffTest();
}

void Sorting::insertion(bool detail)
{
    startEffTest();

    //set number of elm
    for (int nData = 2; nData <= maxSize;nData++)
    {
        insert(nData);
        //check detail process
        if(detail) display();
    }
    endEffTest();
}

void Sorting::bubble(bool detail)
{

    startEffTest();

    //set number of elm
    for (int nData = maxSize; nData > 1; nData --){

        // do bubble only for nData elms
        bubble_(nData);

        //check detail process
        if(detail) display();
    }

    endEffTest();
}

void Sorting::shell(bool detail)
{

    startEffTest();

    //do shell for k
    for(int k = maxSize/2;k >= 1; k/=2){
        selectK(k);
        //check detail process
        if(detail) display();
    }

    endEffTest();
}

void Sorting::merge()
{

    startEffTest();
    // allocate and copy data
    ArrayList *temp = new ArrayList(this->maxSize);

    // fill all element to zero
    for (int i = 0;i<maxSize;i++){
        temp->add(temp->size(),0);
        //increment loopcounter
        loopCounter++;
    }

    //copyArray(data,temp,0,maxSize-1);

    //merge sort for temp input and data input
    merge_(temp,0,maxSize-1);

    //destroy temp
    delete temp;

    endEffTest();
}

void Sorting::quick()
{


    startEffTest();
    //perform recursive quick sort
    quick_(0,maxSize-1);
    endEffTest();
}

int Sorting::findMaxIndex(int n)
{
    // first set max index at zero position
    int maxIndex = 0;
    // scan for index of maximum value
    for(int i = 1;i<n;i++){

        if(data->get(maxIndex) < data->get(i))
            maxIndex = i;

        //increment loopcounter
        loopCounter++;
    }

    return maxIndex;
}

void Sorting::swap(int i, int j)
{
    //swap data i and j
    int temp = data->get(i);
    data->set(i,data->get(j));
    data->set(j,temp);

    //increment swapCounter
    swapCounter++;
}

void Sorting::insert(int n)
{
    //pick insert data at index n-1
    int insertData =  data->get(n-1);
    //set insert index to n - 2
    int insertPos = n-2;

    //check insertion swap
    while (insertPos >= 0 && data->get(insertPos) > insertData) {
        //loop increment
        loopCounter++;

        swap(insertPos,insertPos+1);
        insertPos --;

    }
}

void Sorting::bubble_(int n)
{
    //do bubble
    for (int i = 0;i<n-1;i++)
    {
        //increment loop
        loopCounter++;
        if (data->get(i) > data->get(i+1))
        {
            swap(i,i+1);
        }
    }
}

void Sorting::quick_(int begin, int end)
{
    //check index
    if (end - begin <= 0) return;

    //pick pivot index
    int iPivot = pickPivotIndex(begin,end);

    //swap between index of pivot and last data
    swap(iPivot,end);

    //partition both data sets
    int i = begin, j = end - 1;
    while (i <= j) {
        while (i <= j && data->get(i) < data->get(end)) {i++;//increment loopcounter
            loopCounter++;}
        while (i <= j && data->get(j) >= data->get(end)) {j--;//increment loopcounter
            loopCounter++;}
        if (i < j) swap(i,j);
    }

    //swap i and end (pivot)
    swap(i,end);

    //perform quick sort in two data sets, recursively
    quick_(begin, i-1);
    quick_(i + 1,end);
}

int Sorting::pickPivotIndex(int begin, int end)
{
    // calculate middle position
    int mid = (begin + end) / 2;

    //re-assign variables (easy to call)
    int a = data->get(begin); int b = data->get(mid); int c = data->get(end);

    //check for middle conditions
    if((a >= b && b >= c) || (a <= b && b <= c))
        return mid;
    else if((b >= c && c >= a) || (b <= c && c <= a))
        return end;
    else return begin;
}

void Sorting::selectK(int k)
{
    //do insertion for n element eith k displacement
    for (int i = 0;i < k;i++)
        //do selection sort with k displacement
        for(int j = i;j < maxSize; j+=k){
            int iMin = findMinIndexK(j,k);
            swap(j,iMin);
        }
}

int Sorting::findMinIndexK(int iStart,int k)
{
    // first set min index at first index
    int minIndex = iStart;

    //scan for index of minimum calue
    for(int i = iStart + k; i < maxSize; i++){
        //increment loop
        loopCounter++;
        if (data->get(i) < data->get(minIndex))
            minIndex = i;
    }
    //return index of minimum value
    return minIndex;
}

void Sorting::copyArray(ArrayList *src, ArrayList *desc, int begin, int end)
{
   for (int i = begin; i <= end; i++)
   {
       desc->set(i,src->get(i));
       //increment loopcounter
       loopCounter++;
   }

}

void Sorting::merge_(ArrayList *result, int begin, int end)
{
    //check number of data
    if(end - begin <= 0)return;
    //continue divide data
    merge_(result,begin,(begin + end) / 2);
    merge_(result,(begin + end) / 2 + 1,end);
    //merge sort
    int i = begin, j = (begin + end) / 2 + 1;
    for (int k = begin; k <= end; k++){

        //increment loopcounter
        loopCounter++;

        if(i > (begin + end) / 2) //remain only j data, select d[j]
            result->set(k,data->get(j++));
        else if(j > end) //remain only j, select d[i]
            result->set(k,data->get(i++));
        else if(data->get(i) > data->get(j)) //d[i] > d[j], select d[j]
            result->set(k,data->get(j++));
        else result->set(k,data->get(i++)); //d[i] > d[j], select d[i]
    }

    //update result to data before return
    copyArray(result,data,begin,end);
}
