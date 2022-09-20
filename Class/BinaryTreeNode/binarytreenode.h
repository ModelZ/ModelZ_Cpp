#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <iostream>

class BinaryTreeNode
{
//data
public:
    int element;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

//method
public:
    BinaryTreeNode(int element = 0,
                   BinaryTreeNode *left = NULL,
                   BinaryTreeNode *right = NULL);
};

#endif // BINARYTREENODE_H
