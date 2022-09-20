#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "../BinaryTreeNode/binarytreenode.h"

enum ORDER {IN_ORDER,PRE_ORDER,POST_ORDER};

class BinarySearchTree
{
//data
private:
    BinaryTreeNode *root;
    int size;

//method
public:
    BinarySearchTree(); //constructor
    ~BinarySearchTree(); //destructor

    //basic method
    void insert(int e); //insert new element
    void remove(int e); //remove element
    void clrsc();

    //display
    void display(ORDER o = IN_ORDER); // display

private:
    BinaryTreeNode *findMin(BinaryTreeNode *p);
    BinaryTreeNode *findMax(BinaryTreeNode *p);

    void removeTree(BinaryTreeNode *&p); //recursively remove
    void insertTree(BinaryTreeNode *&p,int e);
    void displayInOrder(BinaryTreeNode *p);
    void displayPreOrder(BinaryTreeNode *p);
    void displayPostOrder(BinaryTreeNode *p);
    void remove(BinaryTreeNode *&p,int n);


};

#endif // BINARYSEARCHTREE_H
