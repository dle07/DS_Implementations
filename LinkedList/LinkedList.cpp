#include "LinkedList.hpp"


template <typename xType>
LinkedList<xType> :: LinkedList():itemCount(0), head(nullptr){

}

template <typename xType>
LinkedList<xType> :: ~LinkedList(){
    Node<xType>* temp = head;
    Node<xType>* curr = head;
    while( curr ){
        temp = curr ->getNext();
        delete curr;
        curr = temp;
    }
}

//Deep Copy Constructor
template <typename xType>
LinkedList<xType> :: LinkedList(const LinkedList<xType> &target){
    itemCount = target->getItemCount();
    this->head = new Node<xType> (target.getHead()->getItem() );
    Node<xType>* originalCurr = head;
    Node<xType>* targetCurr = target.getHead()->getNext();
    while(targetCurr){
        Node<xType>* temp = new Node<xType>(targetCurr->getItem());
        originalCurr->setNext(temp);
        originalCurr = temp;
        targetCurr = targetCurr->getNext(); 
    }

}


template <typename xType>
Node<xType>* LinkedList<xType> :: getHead(){
    return this->head;
}

template <typename xType>
bool LinkedList<xType> ::  empty(){
    return this->head == NULL? true : false;
}

template <typename xType>
const xType LinkedList<xType> :: front() const{
    return this->head == NULL ? NULL : this->head->getItem();
}

template <typename xType>
void LinkedList<xType> :: addEnd(xType elem){
    Node<xType>* curr = head;
    while( curr ->getNext() != NULL){
        curr = curr->getNext();
    }
    curr->setNext( new Node<xType>(elem));
    itemCount ++;
}

template <typename xType>
void LinkedList<xType> :: addFront( xType elem){
    if( head ==NULL){
        head = new Node<xType>(elem);
    }else{
    Node<xType>* temp = new Node<xType>(elem);
    temp->setNext(head);
    head = temp;
    }
    itemCount ++;
}

template <typename xType>
void LinkedList<xType> :: removeFirstOccurrence(xType elem){
    if( !head )return;
    if( head ->getItem() == elem){
        Node<xType>* temp = head;
        head = head->getNext();
        delete temp;
        this -> itemCount--;
        return;
    }
    Node<xType>* prev = head;
    Node<xType>* curr = head;
    while(curr){
        if( curr ->getItem() ==  elem){
            prev->setNext( curr ->getNext() );
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }
    this->itemCount --;
}


template <typename xType>
void LinkedList<xType> :: removeFront (){
    if( head == NULL) return;
    else if( head ->getNext() == NULL){
        delete head;
        head = NULL;
    }
    else{
        Node<xType>* temp = head ->getNext();
        delete head;
        head = temp;
    }
    itemCount --;

}


template <typename xType>
void LinkedList<xType> :: removeEnd(){
    if( head == NULL)return;
    else if( head ->getNext() == NULL){
        delete head;
    }else{
        Node<xType>* prev = head;
        Node<xType>* curr = head;
        while( curr->getNext()){
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(NULL);
        delete curr;
    }
    itemCount --;
}

template <typename xType>
void LinkedList<xType> ::print(){
    Node<xType>* curr = head;
    while( curr ){
        cout<< curr ->getItem()<<endl;
        curr = curr->getNext();
    }
}

template <typename xType>
bool LinkedList<xType> :: exists (xType target){
    Node<xType>*curr = head;
    while(curr){
        if( curr ->getItem() == target){
            return true;
        }
    }
    return false;
}

template<typename xType>
int LinkedList<xType> :: getItemCount() const{
    return this->itemCount;
}