#include "DoublyLinkedList.hpp"

/*
    Project 3
    Author: Daniel Le
    DoublyLinkedList Implementation Project

*/

/*
Creates a Deep copy of a DoublyLinkedList by looping through the given List

*/
//Default no-args constructor
template<typename ItemType>
DoublyLinkedList <ItemType> :: DoublyLinkedList():
head(nullptr),tail(nullptr), itemCount(0){
    
}

/** Deep Copy Constructor */
template <typename ItemType>
DoublyLinkedList <ItemType> :: DoublyLinkedList(const DoublyLinkedList<ItemType> &target){
this->itemCount = target.itemCount;
// Case 1) Copy List has 0 items
if( target.head == nullptr){
    head = nullptr;
    tail = nullptr;
    return;
}
//creates a node on, head is set to that node
head = new DoubleNode<ItemType>(target.head->getItem());
//Case 2) Copy List has only 1 item
//Checks to see if the List has only one node, if so, set the tail to the head,return;
if( target.head->getNext == nullptr ){
    tail = head;
    return;
}
/* Case 3) Copy List's itemCount >1
    */
DoubleNode <ItemType> * prev=head;
DoubleNode <ItemType> * currOriginalPtr=target.head;
    while(currOriginalPtr->getNext()){
        //Creates a new DoubleNode, advances the next node, 
        currOriginalPtr = currOriginalPtr->getNext();
        DoubleNode<ItemType> temp = new DoubleNode<ItemType>(currOriginalPtr->getItem());
        temp.setPrevious(prev);
        prev ->setNext(temp);
        prev = prev->getNext();

    }
    tail=currOriginalPtr;
}

/** Destructor To clear up memory once a DoublyLinkedList goes out of scope */
template <typename ItemType>
DoublyLinkedList <ItemType> :: ~DoublyLinkedList(){
    // No need to check for these conditions as the loop takes care of these cases
    /* if(itemCount == 0 ) return;
    if(itemCount == 1 ) { delete head; return;}  */
    //Loop through List, deleting each node
    DoubleNode<ItemType>* curr = head;
    while(curr){
        DoubleNode<ItemType>* tempNext = curr->getNext();
        delete curr;
        curr = tempNext;
    }
}

//
template <typename ItemType>
void DoublyLinkedList <ItemType> :: add(const ItemType &item){
    // If the list is empty
    if( this-> head == nullptr){
        this->head = new DoubleNode <ItemType>(item);
        tail = head;
        this->itemCount ++;
    }
    //If the list isn't empty
    if(this -> tail != nullptr){
    DoubleNode <ItemType>* temp = new DoubleNode<ItemType>(item);
    temp->setPrevious(this->tail->getPrevious());
    this->tail->getPrevious()->setNext(temp);
    tail = temp;
    this->itemCount++;
    }
}


//Insert has quite the number of edge cases, be wary young one.
template<typename ItemType>
bool DoublyLinkedList <ItemType> :: insert(const ItemType &item, const int &position){

    //No position exists, return false
    if(position > itemCount+1 || position <=0 )return false;
    //Edge Case 1) Where the insertion node is at the beginning and the position is at 1, no need to check for positoin ==1, as it's implied by out first if statement above
    else if( head == nullptr ){
        head = new DoubleNode<ItemType>(item);
        tail = head;
    }
    //Edge Case 1) If the insertion position is at the beginning, creates a pointer to the head node, sets the head to a newly created DoubleNode, sets head-> next to the temp, and finally established the link by setting temp's prev to the head
    else if( position ==1 ){
        DoubleNode<ItemType>* temp = head;
        head= new DoubleNode<ItemType>(item);
        head->setNext(temp);
        temp->setPrevious(head);
    }
    //Edge case 2) If the insertion position is at the very end of the list, traverse to the last node, create a new node, set the last node's next field to the address of the newly created node, set the newly created node's prev field to the curr node, set tail  to the newly created node
    else if(position == itemCount +1){
        DoubleNode <ItemType> * curr = head;
        // To traverse to the end, we can do the classic while(curr->getNext()) method, or we can use a for loop, for( int i=1; i<itemCount; i++){ curr = curr->getNext();}
        while(curr->getNext()){
            curr = curr->getNext();
        }
        DoubleNode<ItemType>* temp = new DoubleNode<ItemType>(item);
        curr->setNext(temp);
        temp->setPrevious(curr);
        tail=temp;
    }
    //Majority of the case, where the insertion position is between two adjacent DoubleNodes
    else{
        DoubleNode <ItemType>* curr = head;
        for( int i = 1; i< position; i++){
        curr = curr->getNext();
        }
        DoubleNode<ItemType> temp = new DoubleNode<ItemType>(item);
        temp->setPrevious(curr->getPrevious());
        temp->setNext(curr->getNext());
        curr->getPrevious()->setNext(temp);
        curr->getNext()->setPrevious(temp);
    }
    itemCount ++;
    return true;

};

template <typename ItemType>
void DoublyLinkedList <ItemType> :: removeByElement(const ItemType & item){
    DoubleNode<ItemType>* curr = this->head;

    if( curr != nullptr && curr -> getItem() == item){
            //Special case, if target node is at beginning and it's the only node
            if( curr ->getNext() == nullptr){
                delete curr;
                head = nullptr;
                tail = nullptr;
            }else{
                DoubleNode <ItemType>* temp = head ->getNext();
                temp->setPrevious(nullptr);
                delete head;
                head = temp;
            }
            itemCount --;
            return;
    }
    while( curr ){
        if( curr->getItem() == item){
            //Edge case where the node is at the end of the list
            if( curr == this ->tail){
                tail = curr->getPrevious();
                curr->getPrevious()->setNext(nullptr);
                delete curr;
            }else{
                //Average case, target node is in the middle of list
                curr->getPrevious()->setNext(curr->getNext());
                curr->getNext() -> setPrevious( curr-> getPrevious());
                delete curr;
            }
            itemCount--;
            return;
        }
    }
}

template <typename ItemType>
bool DoublyLinkedList <ItemType> :: exists( const ItemType &item){
    DoubleNode<ItemType>* curr = this->head;
    while(curr){
        if( curr->getItem() == item){
            return true;
        }
    }
    return false;
}

template <typename ItemType>
bool DoublyLinkedList <ItemType> :: remove(const int &position){
    //No such DoubleNode exists in the List, return false immediately
    if( position <0 || position > this-> itemCount) return false;
    else if( position == 1){
        if( head-> getNext() == nullptr){
            delete head;
            head == nullptr;
            tail == nullptr;
        }else{
            head->getNext()->setPrevious(nullptr);
            delete head;
        }
    }
    else if(position == itemCount){
        DoubleNode<ItemType>* curr = head;
        while(curr->getNext()){
            curr=curr->getNext();
            curr->getPrevious()->setNext(nullptr);
            tail = curr->getPrevious();
            delete curr;
        }
    }else{
        DoubleNode<ItemType>* curr = head;
        for(int i=1; i< position ;i++){
            curr = curr->getNext();
            curr->getPrevious()->setNext(curr->getNext());
            curr->getNext()->setPrevious(curr->getPrevious());
            delete curr;
        }
    }
    
    itemCount --;
    return true;
}


template <typename ItemType>
int DoublyLinkedList<ItemType> :: getSize() const{
    return this->itemCount;
}

template <typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType> :: getHeadPtr() const{
    return this->head;
}

template <typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType> :: getTailptr() const{
    return this-> tail;
}
template <typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType> :: getAtPos(const int &pos) const{
    DoubleNode<ItemType>* curr = head;
    if( pos <0 || pos > itemCount){
        return head;
    }
    for( int i=1; i< pos; i++){
        curr = curr->getNext();
    }
    return curr;
}

template <typename ItemType>
bool DoublyLinkedList<ItemType> :: isEmpty() const{
    return itemCount > 0 ? false :true ;
}

template <typename ItemType>
void DoublyLinkedList<ItemType> :: clear(){

}

template <typename ItemType>
int DoublyLinkedList<ItemType> :: getIndexOf(const ItemType & item) const{
    DoubleNode<ItemType>* curr= head;
    int index = 1;
    if( head ==nullptr) return -1;
    while( curr->getNext()){
        if( curr->getItem() == item){
            return index;
        }
        curr = curr->getNext();
        index ++;
    }
    return -1;
}

template <typename ItemType>
void DoublyLinkedList<ItemType> ::display() const{
    
        DoubleNode<ItemType>* curr = head;
        while( curr){
            std::cout<<curr->getItem()<<std::endl;
            curr = curr->getNext();
        }

   

}

template <typename ItemType>
void DoublyLinkedList<ItemType> :: displayBackwards() const{
    
    
    DoubleNode<ItemType>* curr = tail;
    while( curr ){
        std :: cout<< curr ->getItem()<<endl;
        curr = curr->getPrevious();
    }
    
    
    /*
    <<<<<<<<<<<<<<<<< None recursive way, intutive way   >>>>>>>>>>>>>
    vector <ItemType> myVector;
    DoubleNode <ItemType>* curr = head;
    while( curr){
        myVector.push_back(curr->getItem());
        curr = curr->getNext();
    }
    for( int i= myVector.size()-1; i >=0; i++){
        cout<< myVector[i]<<endl;
    }
    */
}


/*
Bonus Feature
Define the calling list as a set of ordered nodes, $L1 = {4, 2, 8 ,5, 8}$, and define the list that is passed as a parameter as a set 
of ordered nodes, $L2 = {5, 1, 8, 4, 5, 9}$. L1.interleave(L2) yields the set ${4, 5, 2, 1, 8, 8, 5, 4, 8, 5, 9}$. In other words,
to create the interleaved list, first add a node from L1, then one from L2, and then repeat as many times as necessary.
If there are any nodes left over in L1 or L2 exclusively, append them to the end of the list.

{4, 2, 8 ,5, 8}
{5, 1, 8, 4, 5, 9}
{4, 5, 2, 1, 8, 8, 5, 4, 8, 5, 9}

!!!  This makes a deep copy, does not modify calling list, nor paramater list   !!!
*/
template <typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType> :: interleave( 
    const DoublyLinkedList<ItemType> & a_list){

        DoublyLinkedList result ();
        
        DoubleNode<ItemType>* prev;
        DoubleNode<ItemType>* curr;

        DoubleNode<ItemType>* first = this ->head;
        DoubleNode<ItemType>* second = a_list.getHeadPtr();
        // Checks to see if either one of the lists given is empty or not, assigns the
        //head pointer of result to the first non null head we see
        if( first !=NULL){
            DoubleNode<ItemType> * temp = new DoubleNode(this->head->getItem());
            result ->getHeadptr() = temp;
            prev = temp;
            curr = temp;
            first = this -> head ->getNext();
            
        }else if( second != NULL){
            DoubleNode<ItemType> * temp = new DoubleNode(a_list ->getHeadPtr() -> getItem());
            result ->getHeadptr() = temp;
            prev = temp;
            curr = temp;
            second = second->getNext();
        }
        //In order to be consistent with the swapping pattern we need to check to see if the paramater list has a node,
        //then add that node to our result, and assign prev to that node
        if( second != nullptr){
            DoubleNode<ItemType> * temp = new DoubleNode( a_list->getHeadPtr()->getItem());
            prev->setNext(temp);
            temp->setPrevious(prev);
            curr = temp;
            second = second ->getNext();
        }
        
        while(first || second){
            if(first){
                DoubleNode<ItemType>* temp = new DoubleNode(first->getItem());
                curr = temp;
                prev->setNext(curr);
                curr ->getPrevious(prev);
                first = first->getNext();
            }
            if(second){ 
                DoubleNode<ItemType>* temp = new DoubleNode(second ->getItem());
                curr = temp;
                prev->setNext(curr);
                curr ->getPrevious(prev);
                second = second->getNext(); 
            }
        }
        result.getTailPtr() = curr;
        return result;
}



