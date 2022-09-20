#include "binarysearchtree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

BinarySearchTree::BinarySearchTree()
    :root(NULL)
{

}

BinarySearchTree::~BinarySearchTree()
{
    removeTree(root);
}

void BinarySearchTree::insert(int e)
{
    insertTree(root,e);
}

void BinarySearchTree::remove(int e)
{
    if(root == NULL){
         cerr<< "Error empty tree"<<endl;
    }
    else {
         remove(root,e);
    }
}

void BinarySearchTree::clrsc()
{
     system("cls");
}

void BinarySearchTree::remove(BinaryTreeNode *&p,int e)
{


    BinaryTreeNode *temp;
    if(p == NULL){
        cerr <<"Error: element is not found"<<endl;
    }
    else {
        if (e < p->element){
            remove(p->left,e);
        }
            else if (e > p->element) {
                remove(p->right,e);
            }
        else {

            if(p->left != NULL && p->right != NULL){
                temp = findMin(p->left);
                p->element = temp->element;

                remove(p->right,temp->element);
            }


            else {
                temp = p;
                if (p->left == NULL){
                    p = p->right;
                }
                else if(p->right == NULL){
                   p = p->left;
                }
                else{p = NULL;}

               delete temp;

            }
        }

        }
}

void BinarySearchTree::display(ORDER o)
{
    cout << "Tree: ";
    switch (o) {
    case PRE_ORDER:
        displayPreOrder(root);
        break;
    case POST_ORDER:
        displayPostOrder(root);
        break;
    default: //IN_ORDER
        displayInOrder(root);
        break;
    }
    cout <<endl;
}

void BinarySearchTree::removeTree(BinaryTreeNode *&p)
{
    if(p != NULL)
    {
        //recursive remove left
        if(p->left != NULL) removeTree(p->left);
        //recursive remove right
        if(p->right != NULL) removeTree(p->right);
        //remove node p
        delete p;
        p = NULL;
    }
}

void BinarySearchTree::insertTree(BinaryTreeNode *&root, int e)
{
    if(root == NULL) //add new bst node if tree is empty
        root = new BinaryTreeNode(e,NULL,NULL);
    else if(root->element > e) //add element left if element <= root
        insertTree(root->left,e);
    else //add element right if element > root
        insertTree(root->right,e);

    size++;
    return;
}

BinaryTreeNode *BinarySearchTree::findMin(BinaryTreeNode *p)
{
    if (p == NULL){
        return NULL;
    }
    else if (p->left == NULL) {
       return p;
    }
    else
    {
        return findMin(p->left);
    }
}

BinaryTreeNode *BinarySearchTree::findMax(BinaryTreeNode *p)
{
    if (p == NULL){
        return NULL;
    }
    else if (p->right == NULL) {
       return p;
    }
    else
    {
        return findMin(p->right);
    }
}

void BinarySearchTree::displayInOrder(BinaryTreeNode *p)
{
    //(L,N,R)

    if(p != NULL)
    {
        cout << "(";
        if (p->left != NULL)
            displayInOrder(p->left);
        cout << "," << p->element <<",";
        if (p->right != NULL)
            displayInOrder(p->right);
        cout << ")";
    }
}

void BinarySearchTree::displayPreOrder(BinaryTreeNode *p)
{
    //(N,L,R)

    if(p != NULL)
    {
        cout << "(";
        cout << "," << p->element <<",";
        if (p->left != NULL) displayInOrder(p->left);
        if (p->right != NULL) displayInOrder(p->right);
        cout << ")";
    }
}

void BinarySearchTree::displayPostOrder(BinaryTreeNode *p)
{
    //(L,R,N)

    if(p != NULL)
    {
        cout << "(";
        if (p->left != NULL) displayInOrder(p->left);
        if (p->right != NULL) displayInOrder(p->right);
        cout << "," << p->element <<",";
        cout << ")";
    }
}

