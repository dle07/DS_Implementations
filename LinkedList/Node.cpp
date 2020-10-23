#include "Node.hpp"


template <typename T>
Node <T> :: Node(){

}

template <typename T>
Node <T> :: Node(T data){
    this-> setData(data);
}

template <typename T>
T Node <T> ::  getItem(){
    return this->data;
}

template <typename T>
Node* Node <T> :: getNext(){
    return this->next;
}

template <typename T>
void Node <T> :: setNext(Node* node){
    this->next = node;
}

template <typename T>
void Node <T> :: setData(T data){
    this->data = data;
}
