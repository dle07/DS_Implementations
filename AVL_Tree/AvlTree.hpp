#ifndef AVLTREE_
#define AVLTREE_
/*
Author: Daniel Le

*/
#include "Node.hpp"
#include <queue>
#include <iostream>

using std:: endl;
using std:: cout;
using std:: string;

template <typename xType>
class AvlTree{

    public:
    AvlTree();
    Node<xType>* root_;
    void insert(xType dataVal);   //Function overloading, insert(xTpe data calls the 2-arg function)
    void insert(Node<xType>* root,xType dataVal);
    bool search(xType dataVal);     //Recursive search
    bool search(Node<xType>* root, xType dataVal);//Actual implementation

    bool iSearch(xType dataVal);    //iterative search

    Node<xType>* max();   //returns node pointing to max value
    Node<xType>* min();   //returns node pointing to min value

    int height();
    int findHeight(Node<xType>* root);
    //Traversal Algorithmns
    void bFS(); //Breadth First Search, level order traversal using std :: queue
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();

    void preOrderTraversalImpl(Node<xType>* root);
    void inOrderTraversalImpl(Node<xType>* root);
    void postOrderTraversalImpl(Node<xType>* root);




};
#include "AvlTree.cpp"


#endif