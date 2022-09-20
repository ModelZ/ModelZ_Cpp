#ifndef CHAINNODE_H
#define CHAINNODE_H

#include <stdlib.h>

class ChainNode
{
    //data
public:
    int element;
    ChainNode *next;

    //Method
public:
    ChainNode(int e = 0,ChainNode *p = NULL); //instructor
};

#endif // CHAINNODE_H
