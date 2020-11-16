#include "StackList.hpp"



template <typename xType>
StackList<xType> :: StackList():itemCount(0),head(NULL){
    
}

template <typename xType>
StackList<xType> :: ~StackList(){

    Node<xType>* temp = head;
    Node<xType>* curr = head;
    while( curr ){
        temp = curr ->getNext();
        delete curr;
        curr = temp;
    }
}

template <typename xType>
StackList<xType> :: StackList(const StackList<xType> &target){
    itemCount = target.itemCount;
    Node<xType>* copyNode = a_stack.head;
    Node<xType>* curr = 
}