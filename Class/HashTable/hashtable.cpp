#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable()
{
    //set maxSize
    maxSize = HASH_DEFAULT_SIZE;
    //set curSize
    curSize = 0;

    // allocate table with default size
    table = new ArrayList(maxSize);

    //set all entry to "not set" status
    for(int i = 0; i < maxSize;i++)
        table->add(i,-1);
}

HashTable::~HashTable()
{
    //destroy "table"
    delete table;
}

void HashTable::addKey(int key)
{
    //try to input i from 0 -> maxSize - 1
    for(int i = 0;i < maxSize; i++){

        //find index for key
        int index = hashFunction(key, i);

        //check duplicated key
        if(key == table->get(index)){
            cerr << "Error: Duplicated Key!\n";
            return;
        }

        //check elm at index
        if (table->get(index) < 0)
        {
            //add element at index
            table->set(index,key);
            //increment curSize
            curSize++;
            //exit loop
            break;
        }

            cout << "Collision Here!!!\n";

    }

    //rehashing here
    if (((float)curSize / (float)maxSize)*100 >= REHASH_SIZE_PERCENTAGE_CHECKER){
        rehashing();
    }
}

void HashTable::display()
{
    //display table (in horizontal)
    for (int i = 0;i<maxSize;i++){
        printf("%4d: ",i);
        if(table->get(i) < 0)
            printf("-\n");
        else
            printf("%d\n",table->get(i));
    }
    //display % used
    printf("Data Used: %.2f%%\n",((float)curSize / (float)maxSize)*100);
    printf("(Rehashing when data exceed %.2f%%, expand size %.2f times)\n"
    ,REHASH_SIZE_PERCENTAGE_CHECKER,REHASH_EXPAND_RATIO);
}

int HashTable::removeKey(int index)
{
    //if curSize == 0
    if(curSize <= 0)
    {
        cerr << "Error: Table is empty!!\n";
        return -1;
    }
    else if(index >= maxSize) //upper bound Error
    {
        cerr << "Error: Index is over than maxSize!!\n";
        return -1;
    }else if(index < 0) //lower bound Error
    {
        cerr << "Error: Index is less than 0!!\n";
        return -1;
    }

    //if value of index is empty
    if(table->get(index) < 0)
    {
        cerr << "Error: Value in index ["<<index<<"] is Empty!!\n";
        return -1;
    }

    //All Fine
    //remove key process
    int value = table->get(index); //keep value
    table->set(index,-1); // set value to empty
    return value;
}

int HashTable::searchKey(int key)
{
    //if curSize == 0
    if(curSize <= 0)
    {
        cerr << "Error: Table is empty!!\n";
        return -1;
    }

    //search 0 -> maxSize -1
    for (int i = 0; i < maxSize; i++)
    {
        int index = hashFunction(key,i);
        //check key == value[index]
        if(key == table->get(index))
        {
            return index;
        }
    }
    //if isnt exist
    cerr << "Error: Index of Key ["<<key<<"] isn't exist\n";
    return -1;
}

void HashTable::clearTable()
{
    //build new hashtable
    ArrayList *newTable = new ArrayList(HASH_DEFAULT_SIZE);
    //delete old table
    delete table;
    //set table point to newTable
    table = newTable;
    //set initial
    curSize = 0;
    maxSize = HASH_DEFAULT_SIZE;

    //set all entry to "not set" status
    for(int i = 0; i < HASH_DEFAULT_SIZE;i++)
        table->add(i,-1);

    cout << "Clear HashTable Completed!!\n";

}

int HashTable::hashFunction(int key, int i)
{
    //Hash function H(key,i) = ((key % maxSize) + f(i)) % maxSize
    //Linear Probing f(i) = i
    return ((key % maxSize) + i) % maxSize;

}

void HashTable::rehashing()
{

    //display old table
    //display();


    cout << "rehashing here.......\n";

    //size is already exceeded
    // - expand REHASH_EXPAND_RATIO
    int oldMaxSize = maxSize;

    maxSize = (float)maxSize * REHASH_EXPAND_RATIO;

    // create new table with REHASH_EXPAND_RATIO times
    ArrayList *newTable = new ArrayList(maxSize);

    // set newCurSize to 0
    int newCurSize = 0;

    //fill all elm of newtable to "not set" (-1)
    for (int i = 0;i < maxSize;i++)
        newTable->add(i, -1);

    //scan all value in old table and then put to new table
    for (int i = 0;i < oldMaxSize; i++) //maxSize is size of old table
    {
        if(table->get(i) >= 0) //has value in old table at i
        {
            for(int j = 0; j < maxSize; j++)
            {
                int newIndex = hashFunction(table->get(i),j);
                if(newTable->get(newIndex) < 0)
                {
                    newTable->set(newIndex,table->get(i));
                    newCurSize++;
                    break;
                }
                 cout << "Collision Here!!!\n";
            }
        }
    }

    // - destroy old table
    delete table;

    // - set new table to current table
    table = newTable;
    curSize = newCurSize;

}
