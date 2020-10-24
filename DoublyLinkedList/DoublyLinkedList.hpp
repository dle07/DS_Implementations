#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
#include"DoubleNode.hpp"
#include <vector>
#include <string>

using std :: vector;
using std :: cout;
using std :: endl;


template <typename ItemType>
class DoublyLinkedList{

    private:
    DoubleNode <ItemType>* head;
    DoubleNode <ItemType>* tail;
    int itemCount;

   public:
   DoublyLinkedList();

   //Copy Constructor 
   DoublyLinkedList(const DoublyLinkedList<ItemType> &target);

   //Destructor
   ~DoublyLinkedList();

    /** Adds a element to the back of the list */
    void add(const ItemType &item);

    /** inserts item at position in caller list */
   bool insert(const ItemType &item, const int &position);

   /** removes first instance of the element in the list */
    void removeByElement( const ItemType & item);

    /** checks to see if a element in the list exists or not */
    bool exists(const ItemType &item);

    /** removes the node at position */
   bool remove(const int &position);           
    
    /**  returns the number of the nodes in the calling list*/
   int getSize() const;                        
       // returns the number of the nodes in the calling list
    
    // returns a copy of the headPtr
   DoubleNode<ItemType> *getHeadPtr() const;   
       
    /** Returns the tailPtr */  
    DoubleNode<ItemType> *getTailptr() const;

   DoubleNode<ItemType> *getAtPos(const int &pos) const; 
   // returns a pointer to the node located at pos

   bool isEmpty() const;                       
       // returns whether the calling list is empty

   void clear();                               
       // clears the list

   int getIndexOf(const ItemType &item) const; 
       // returns the position of the given item in the list, -1 otherwise

   void display() const;                       
       // prints the contents of the calling list in order
    
   void displayBackwards() const;              
       // prints the contents of the calling list in reverse order

   DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list); 
       // returns the interleaved list of the calling and parameter lists
};


#include "DoublyLinkedList.cpp"

#endif