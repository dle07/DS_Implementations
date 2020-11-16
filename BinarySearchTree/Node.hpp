#ifndef NODE_
#define NODE_

template<typename xType>
class Node{

    public:
    xType data_;
    Node <xType>* left_;
    Node <xType>* right_;
    Node();
    Node(xType data);


    

};  
#include "Node.cpp"
//includes Node.cpp because this is a generic interface
#endif