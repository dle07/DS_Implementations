
#include "AvlTree.hpp"
#include "./Node.hpp"


template <typename xType>
AvlTree<xType> :: AvlTree() : root_(nullptr){

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
void AvlTree<xType> :: insert(Node<xType>* root ,xType dataVal){
    if( root_ == nullptr){
        root_ = new Node<xType>  (dataVal);
    }
    else if( dataVal == root-> data_) return; // No duplicates
    else if( dataVal < root ->data_){ //data to be inserted is less than
        if( root->left_ == nullptr){
            root->left_ = new Node<xType>(dataVal);
            return;
        }
        insert(root->left_,dataVal);
        
    }else if( dataVal > root->data_){             //data to be inserted is greater than the current node
        if( root->right_ == nullptr){
            root->right_ = new Node<xType>(dataVal);
            return;
        }
        insert( root->right_ , dataVal);
    }
}

template<typename xType>
void AvlTree<xType> :: insert(xType dataVal){
    this->insert(this->root_ , dataVal);
}


template <typename xType>
bool AvlTree<xType> :: search( xType dataVal){
    return search(this->root_,dataVal);
}

template <typename xType>
bool AvlTree<xType> :: search(Node<xType>* root, xType dataVal ){
    if(root==nullptr)return false;      //Exit condition
    else if( root->data_ == dataVal) return true;       //We've found it, congrats.
    else if ( dataVal < root->data_) search(root->left_ , dataVal); // is the data to the right?
    else search(root->right_, dataVal); //if the data to be found is to the right

}

template<typename xType>
bool AvlTree<xType> :: iSearch(xType dataValue){
    Node<xType>* curr = this->root_;
    while( curr ){
        xType currValue = curr->data_;
        if( curr->data_ == currValue ) return true;
        else if( dataValue < currValue ) curr = curr->left_;
        else curr = curr->right_;
    }
    return false;
}

template <typename xType>
Node<xType>* AvlTree<xType> :: max()
{
    Node<xType>* res = nullptr;
    Node<xType>* temp = root_;
    while( temp ){
        res = temp;
        temp = temp->right_;
    }
    return res;
}

template <typename xType>
Node<xType>* AvlTree<xType> :: min()
{
    Node<xType>* res = nullptr;
    Node<xType>* temp = root_;
    while( temp ){
        res = temp;
        temp = temp->left_;
    }
    return res;
}


template <typename xType>
int AvlTree<xType> :: height(){
    return findHeight(this->root_);
}

template<typename xType>
int AvlTree<xType> :: findHeight(Node<xType>* root)
{
    if(root == nullptr) return -1;
    int leftHeight = findHeight(root->left_);
    int rightHeight = findHeight (root->right_);
    return leftHeight > rightHeight ? leftHeight +1 : rightHeight +1 ;
}





// TRAVERSALS
template <typename xType>
void AvlTree<xType> :: bFS()
{
    if( this->root_ == nullptr) return;
    std :: queue< Node<xType>* > myQueue;
    myQueue.push(this->root_); // Adds Root to the Queue
    while( !myQueue.empty()){

        Node<xType>* curr = myQueue.front();

        cout<< curr->data_<<endl; //Here we can "Visit" the data or perform anything we wanna
        if( curr-> left_ ) myQueue.push( curr -> left_);
        if( curr-> right_ ) myQueue.push( curr -> right_);
        myQueue.pop();
    }
}


template <typename xType>
void AvlTree<xType> :: preOrderTraversal(){
     preOrderTraversalImpl(this->root_);
}

template<typename xType>
void AvlTree<xType> :: inOrderTraversal(){
    inOrderTraversalImpl(this->root_);
}

template<typename xType>
void AvlTree<xType> :: postOrderTraversal()
{
    postOrderTraversalImpl(this->root_);
}


//*Node, checking for existence of right and left field before recurisvely calling it is "redundant" but it doesn't matter in
// terms of efficency, either way, we're performing one comparison, if we check for existence, and the pass fails, 
//the checking of root == nullptr ? won't even hit, so we're fine
//Actual Recursive Implementation
template<typename xType>
void AvlTree<xType> :: preOrderTraversalImpl(Node<xType>* root){
    //1) Access Data, Go Left, Go Right
    if(root==nullptr) return;       //Exit condition
    cout<<root->data<<endl;
    if(root->left_) inOrderTraversalImpl(root ->left_); //Go left
    if(root->right_) inOrderTraversalImpl(root->right_);    //Go right
}

template<typename xType>
void AvlTree<xType> :: inOrderTraversalImpl(Node<xType>* root)
{       // Go left as possible, print current node, go right, effectively visits nodes in sequential order
    if(root == nullptr) return;     //exit condition
    if(root->left_) inOrderTraversalImpl(root ->left_); //Go left
    cout<<root->data_<<endl;                            //Print Data
    if(root->right_) inOrderTraversalImpl(root->right_);    //Go right
}

template<typename xType>
void AvlTree<xType> :: postOrderTraversalImpl(Node<xType>* root)
{
    //Go Left, Go right, visit data, effectively tries to visit leftmost nodes first
    if(root == nullptr) return;     //exit
    if( root->left_ )postOrderTraversalImpl(root->left_);   
    if( root->right_ )postOrderTraversalImpl(root->right_);
    cout<<root->data_<<endl;
}


template <typename xType>
void AvlTree<xType>:: printRootToLeaf(Node<xType>* root){
    if( root == nullptr){
        return;
    }
    std :: string temp = root->data_;
    dfsPrintRootToLeaf(root,temp);
}


template <typename xType> 
void AvlTree<xType> :: dfsPrintRootToLeaf(Node<xType>* root, string path){
    if( root == nullptr) return;
    path += "->" + root->data_;
    if(isLeaf(root)){
        cout<<path<<endl;
        return;
    }
    dfsPrintRootToLeaf( root -> left, path);
    dfsPrintRootToLeaf( root -> right,path);
}


template<typename xType>
bool AvlTree<xType> :: isLeaf(Node<xType>* root){
        return (!root->left && !root->right);
}


template <typename xType>
void AvlTree<xType> :: iterativeDfs(){

    stack<Node<xType>*> st;
    Node<xType>* curr = root_;
    while(curr || !st.empty()){

        while(curr){
            st.push(curr);
            curr = curr->left_;
        }
        //Curr must be null at this point
        curr = st.top();
        st.pop();
        cout<<curr->data_<<" ";
        curr = curr->right_;
    }
}