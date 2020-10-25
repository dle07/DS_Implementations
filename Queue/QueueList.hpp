#ifndef QUEUE_LIST_
#define QUEUE_LIST_

#include <iostream>


using std :: endl;
using std :: cout;
/*
    Stack Implemented as a modified singly linked list
*/
template<typename xType>
class QueueList{

    private:
    int itemCount;
    Node<xType>* head;
    Node<xType>* tail;


    public:
    QueueList();
    QueueList(const QueueList<xType> &a_queue);
    ~QueueList();
    void enQueue(xType elem);
    void deQueue();
    xType back();
    xType front();
    int size();
    bool empty();
    void display();
    
    

};





#endif

