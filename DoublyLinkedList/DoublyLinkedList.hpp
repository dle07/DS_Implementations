#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
#include"DoubleNode.hpp"
#include <vector>
#include <string>

using std :: vector;
using std :: cout;
using std :: endl;


template <typename xType>
class DoublyLinkedList{

    private:
    DoubleNode <xType>* head;
    DoubleNode <xType>* tail;
    int itemCount;

   public:
   DoublyLinkedList();

   //Copy Constructor 
   DoublyLinkedList(const DoublyLinkedList<xType> &target);

   //Destructor
   ~DoublyLinkedList();

    /** Adds a element to the back of the list */
    void add(const xType &item);

    /** inserts item at position in caller list */
   bool insert(const xType &item, const int &position);

   /** removes first instance of the element in the list */
    void removeByElement( const xType & item);

    /** checks to see if a element in the list exists or not */
    bool exists(const xType &item);
    void setSize(int val);
    /** removes the node at position */
   bool remove(const int &position);           
    
    /**  returns the number of the nodes in the calling list*/
   int getSize() const;                        
       // returns the number of the nodes in the calling list
    
    // returns a copy of the headPtr
   DoubleNode<xType> *getHeadPtr() const;   
       
    /** Returns the tailPtr */  
    DoubleNode<xType> *getTailptr() const;

   DoubleNode<xType> *getAtPos(const int &pos) const; 
   // returns a pointer to the node located at pos

   bool isEmpty() const;                       
       // returns whether the calling list is empty

   void clear();                               
       // clears the list

   int getIndexOf(const xType &item) const; 
       // returns the position of the given item in the list, -1 otherwise

   void display() const;                       
       // prints the contents of the calling list in order
    
   void displayBackwards() const;              
       // prints the contents of the calling list in reverse order

   DoublyLinkedList<xType> interleave(const DoublyLinkedList<xType> &a_list); 
       // returns the interleaved list of the calling and parameter lists

    void setHeadPtr(DoubleNode<xType>* node);
    void setTailPtr(DoubleNode<xType>* node);
};


#include "DoublyLinkedList.cpp"

#endif