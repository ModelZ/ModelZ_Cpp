#include "chainnode.h"
#include <iostream>

using namespace std;

ChainNode::ChainNode(int e, ChainNode *p)
//      : element(e), next(p) //oop style
{
    // explicit
    element = e;
    next = p;
}
