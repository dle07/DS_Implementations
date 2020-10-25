#ifndef NODE_
#define NODE_

template <typename xType>
class Node{

    private:
    xType data;
    Node<xType>* next;

    public:
    Node();
    Node(xType data);
    xType getItem();
    Node<xType>* getNext() const;
    void setNext(Node* node);
    void setData(xType data);

};

#include "Node.cpp"
#endif