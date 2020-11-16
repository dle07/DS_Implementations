#ifndef STACK_LIST_
#define STACK_LIST_


#include "../LinkedList/Node.hpp"
#include "../LinkedList/Node.cpp"


/*
    Singly Linked list approach, requires more code as a destructor is needed,
    and copy constructor requires us to produce a whole copy of the list


*/
template <typename xType>
class StackList{

    private:
    int itemCount;
    Node<xType>* head;

    public:
    StackList();
    ~StackList();
    StackList(const StackList<xType> &target);
    void push(xType elem);
    void pop();
    bool empty();
    xType top();
    int size();

}; //endif


#endif