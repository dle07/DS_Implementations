#ifndef NODE_
#define NODE_

template <typename T>
class Node{
    private:
    ItemType data;
    Node* next;
    public:
    Node();
    Node(T data);
    T getItem();
    Node* getNext();
    void setNext(Node* node);
    void setData( T data);

};


#endif