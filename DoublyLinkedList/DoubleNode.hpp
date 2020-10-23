#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<typename ItemType>
class DoubleNode{

    private:
    ItemType item_;
    DoubleNode <ItemType>* prev;
    DoubleNode <ItemType>* next;
    
    public:
    DoubleNode();
    DoubleNode(ItemType item);
    void setItem(const ItemType &anItem);
    void setPrevious(DoubleNode<ItemType> *previousNodePtr);
    void setNext(DoubleNode<ItemType> *nextNodePtr);
    ItemType getItem() const;
    DoubleNode<ItemType> *getNext() const;
    DoubleNode<ItemType> *getPrevious() const;

    

};  //ends the defintion of the new user defined type
#include "DoubleNode.cpp"
//includes DoubleNode.cpp because this is a generic interface
#endif