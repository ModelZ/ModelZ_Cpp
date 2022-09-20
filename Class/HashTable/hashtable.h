#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASH_DEFAULT_SIZE 2
#define REHASH_SIZE_PERCENTAGE_CHECKER 80.0
#define REHASH_EXPAND_RATIO 2.0

#include "../ArrayList/arraylist.h"

class HashTable : public ArrayList
{
// data member
private:
    ArrayList *table;
    int curSize;
    int maxSize;

public:
    HashTable();
    ~HashTable();

    void addKey(int key);
    void display();
    int removeKey(int index);
    int searchKey(int key);
    void clearTable();

private:
    int hashFunction(int key,int i); //linear probing
    void rehashing();
};

#endif // HASHTABLE_H
