#include "QueueList.hpp"


template<typename xType>
QueueList<xType> :: QueueList():itemCount(0),head(NULL),tail(NULL){

}

template<typename xType>
QueueList<xType> :: QueueList( const QueueList<xType> &a_queue){

    itemCount = a_queue.itemCount;
    if(a_queue.head == NULL ){
        ~QueueList();
        return;
    }
    
    Node<xType>* curr = new Node<xType>(a_queue.head->getItem());
    head = curr;

    Node<xType>* originalQueue = a_queue.head->getNext();
    while( originalQueue ){

        Node<xType>* temp = new Node<xType>(originalQueue->getItem());
        curr->setNext(temp);
        curr = temp;
        originalQueue = originalQueue ->getNext();
    }

    tail = curr;
}


template<typename xType>
QueueList<xType> :: ~QueueList(){

    if(head == NULL){
        return;
    }
    if( head->getNext() == NULL){
        delete head;
        return;
    }
    Node<xType>* curr = head;
    while( curr ){
        Node<xType>* temp = curr ->getNext();
        delete curr;
        curr = temp;
    }

}


template<typename xType>
void QueueList<xType> :: enQueue( xType elem){
    if( tail ==NULL){
        Node<xType>* temp = new Node<xType>(elem);
        head = temp;
        tail =temp;
    }else{
    Node<xType>* temp = new Node<xType>(elem);
    tail->setNext(temp);
    tail = temp;
    }
    itemCount ++;
}

template<typename xType>
void QueueList<xType> :: deQueue(){

    if( head == NULL){
        return;
    }
    if( head ->getNext() == NULL){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        Node<xType>* temp = head ->getNext();
        delete head;
        head = temp;
    }
    itemCount--;
}

template<typename xType>
xType QueueList<xType> :: back(){
    return tail == NULL ? NULL : tail->getItem();
}

template<typename xType>
xType QueueList<xType> :: front(){
    return head == NULL ? NULL : head->getItem();
}

template<typename xType>
int QueueList<xType> :: size(){
     return this->itemCount;
}

template<typename xType>
bool QueueList<xType> :: empty(){
    return itemCount>0 ? false : true;
}

template<typename xType>
void QueueList<xType> :: display(){

    Node<xType>* curr = head;
    while( curr ){
        std :: cout<< curr->getItem()<<endl;
        curr = curr ->getNext();
    }

}