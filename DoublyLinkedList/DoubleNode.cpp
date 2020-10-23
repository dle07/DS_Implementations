/*
    Project 3
    Author: Daniel Le
    Student Doublly Linked List Implememntation Project

*/
#include "DoubleNode.hpp"
template <typename ItemType> 
DoubleNode <ItemType> ::DoubleNode(){

};





template <typename ItemType> 
DoubleNode <ItemType> :: DoubleNode(ItemType item){
    this->item_ = item;
    prev=nullptr;
    next=nullptr;
    
}
template<typename ItemType>
void DoubleNode <ItemType> :: setItem(const ItemType &anItem){
    this->item_ = anItem;
};


template<typename ItemType>
void DoubleNode <ItemType> :: setPrevious(DoubleNode<ItemType> *previousNodePtr){
    this->prev = previousNodePtr;
}

template<typename ItemType>
void DoubleNode <ItemType> :: setNext(DoubleNode<ItemType> *nextNodePtr){
    this->next = nextNodePtr;
}



template<typename ItemType>
ItemType DoubleNode <ItemType>  :: getItem() const {
    return this->item_;
}

template<typename ItemType>
DoubleNode<ItemType>* DoubleNode <ItemType> :: getNext() const{
    return this->next;
}

template<typename ItemType>
DoubleNode<ItemType>* DoubleNode <ItemType> :: getPrevious() const{
    return this->prev;
}





