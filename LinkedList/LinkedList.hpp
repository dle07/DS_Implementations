#ifndef LINKED_LIST_
#define LINKED_LIST_
#include "Node.hpp"
#include <iostream>

using std:: cout;
using std:: endl;
using std:: string;


template <typename xType>
class LinkedList
{
private:
    Node<xType>* head;
    int itemCount;
public:
    LinkedList();
    ~LinkedList();
    LinkedList( const LinkedList<xType> &target);
    
    Node<xType>* getHead();
    bool empty();
    const xType front() const;
    void addEnd(xType elem);
    void addFront(xType elem);
    void removeFirstOccurrence(xType elem);
    void removeFront();
    void removeEnd();
    void print();
    bool exists(xType target);
    int getItemCount() const;

};




#endif