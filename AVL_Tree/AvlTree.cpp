
#include "AvlTree.hpp"
#include "Node.hpp"


template <typename xType>
AvlTree<xType> :: AvlTree() : root(nullptr){

}


/*
Using recurision we will perform insertion, we insert a new node if we find a empty leaf node
1) Termination condition, if the root node is null, that means we have a slot of insertion
2) If the root node isn't null that means we can either insert it to the left or to the right depending on the value comparison
Exit condition root == nullptr, Create a temporary node, set the root to the temporary node
Case 1) data < root->data_ (that is, the root we're comparing is greater than the data to be inserted, we need to travel to the left), we then call insert( root->left, data);
Case 2) data > root->data_ (we travel to the right, data the be inserted is greater than the root data)

*/
template<typename xType>
void AvlTree<xType> :: insert(Node<xType>* root ,xType dataValue){
    if( root == nullptr){
        root = new Node(dataValue);
    }
    else if( root-> data_ == dataValue)return; //no duplicates allowed, 
    else if( dataValue < root->data_){
        insert(root->left_ , dataValue);
    }else if( dataValue > root->data_){
        insert(root->right_ , dataValue);
    }
}

template<typename xType>
void AvlTree<xType> :: insert(xType data){
    this->insert(this->root_,data);
}







// TRAVERSALS
template <typename xType>
void AvlTree<xType> :: BFS(){
    if( this->root_ == nullptr) return;
    std :: queue< Node<xType>* > myQueue;
    myQueue.push(this->root_); // Adds Root to the Queue
    while( !myQueue.empty()){
        Node<xType>* curr = myQueue.front();
        cout<<curr->data_<<endl;
        if( curr-> left_ ) myQueue.push( curr -> left_);
        if( curr-> right_ ) myQueue.push( curr -> right_);
        myQueue.pop();
    }

}
