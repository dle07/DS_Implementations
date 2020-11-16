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
Node* <xType> root_;
void insert(xType data);                //Function overloading, insert(xTpe data calls the 2-arg function)
void insert(Node<xType>* root,xType data);

string char = 3;
//Traversal Algorithmns
void BFS(); //Breadth First Search, level order traversal using std :: queue





};
#include "AvlTree.cpp"


#endif