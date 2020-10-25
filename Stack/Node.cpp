#include "Node.hpp"


template <typename xType>
Node <xType> :: Node() : data(NULL), next(nullptr){
    
}

template <typename xType>
Node <xType> :: Node(xType data):data(data), next(nullptr){
    
}

template <typename xType>
xType Node <xType> ::  getItem(){
    return this->data;
}


template <typename xType>
Node<xType>* Node<xType> :: getNext() const{
    return this->next;
}


template <typename xType>
void Node <xType> :: setNext(Node<xType>* node){
    this->next = node;
}

template <typename xType>
void Node <xType> :: setData(xType data){
    this->data = data;
}
