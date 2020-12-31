#include "PriorityQueue.hpp"



/*
0-Index binary tree representation, 1 index is faster than 0 indexed array representation
let i denote the index of a node,
left child of node i = 2i +1
right child of node i = 2i +2
parent of i = (i -1)/2;

*/

PriorityQueue :: PriorityQueue()
{
    this->type_ = maximum;

}

PriorityQueue :: PriorityQueue(type type_)
{
    this->type_ = type_;
}

PriorityQueue :: ~PriorityQueue()
{

};

PriorityQueue :: PriorityQueue(const PriorityQueue &target){
    this->type_ = target.type_;
    this-> data_ = target.data_;
    this->size_ = target.size_;
}

//By default this is a maximum heap
PriorityQueue :: PriorityQueue(vector<int> vals){  // # of non leaf nodes(n/2)-1,
    this->type_ = maximum;
    this->data_ = vals;
    this->size_ = vals.size();
    int p;
    int j;
        for( int i = (size_/2) -1; i >= 0 ; --i){
            int curr = i; //anchor pointer
            int j = i*2 + 1;
            int p = curr;
            while(j){
                p = curr;
                if(j< size_ && data_[j] > data_[p]) p = j;
                if( j +1 < size_ && data_[j+1]> data_[p]) p = j+1;
                if(p != curr){
                    swap(curr,p);
                    curr = p;
                    j = (curr *2) +1;
                }else{ break; }
            }
        }
    
    
}

/*Heapify Taking in a vector as a paramater, O(n) to create a heap given an array of values 
    We consider all non leaf nodes, and bubble down approriately
*/
PriorityQueue :: PriorityQueue(vector<int> vals, type version){  // # of non leaf nodes(n/2)-1,
    this->type_ = version;
    this->data_ = vals;
    this->size_ = vals.size();
    int p;
    int j;
    if( this ->type_ == maximum){
        for( int i = (size_/2) -1; i >= 0 ; --i){
            int curr = i; //anchor pointer
            int j = i*2 + 1;
            int p = curr;
            while(j){
                p = curr;
                if(j < size_ && data_[j] > data_[p]) p = j;
                if( j +1 < size_ && data_[j+1]> data_[p]) p = j+1;
                
                if(p != curr){
                    swap(curr,p);
                    curr = p;
                    j = (curr *2) +1;
                }else{ break; }
            }
        }
    }else{  //min heap
        for( int i = (size_/2) -1; i >= 0 ; --i){
            int curr = i; //anchor pointer
            int j = i*2 + 1;
            int p = curr;
            while(j){
                p = curr;
                if(j <size_ && data_[j] < data_[p]) p = j;
                if( j +1 < size_ && data_[j+1] <  data_[p]) p = j+1;

                if(p != curr){
                    swap(curr,p);
                    curr = p;
                    j = (curr *2) +1;
                }else{ break; }
            }
        }

    }
    
}

/* In heaps we send an element from rightmost leaf to the root, we bubble it up if the parent is
not in it's "right spot" depending on the type of priority queue. Say we have a default priority queue, we bubble
it up if the parent element is less than the element to be inserted

*/
void PriorityQueue :: push(int val){
    if( this->size_ == data_.size()){
        data_.push_back(val);
    }else{
        this->data_[size_] = val;
    }
    ++size_;
    int curr = size_-1; //indices;
    int parent = (curr - 1)/2;
    
    if( this->type_ == maximum){    //max heap
        while( parent >=0){//If there's a valid parent to compare with
            if( data_[curr] >  data_[parent]){
                swap(curr,parent);
                curr = parent;
                parent = (curr - 1)/2;
            }else{ break; }//No valid swap, break
        }
    }
    else{//this is a min heap
        while(parent >=0){
            if( data_[curr] <  data_[parent]){
                swap(curr,parent);
                curr = parent;
                parent = (curr - 1)/2;
            }else{ break; }//No valid swap, break
        }
    }
}

//can catch and throw an exception here(if heap is empty), but for simplicity i wont implement this feature
int PriorityQueue :: front(){
    if(this->data_.empty()){
        return -1;
    }
    return data_[0];
}
/* O(log n) time
When removing from a heap we always remove the first element arr[0],
We swap the last element in the array with arr[0] (the root), delete arr[n-1] where n = arr.size()
We then bubble the top element downwards if needed inorder to ensure we still have a heap
Inorder to remove, we need to compare the children of the elements, keep track of which of the two has higher priority
then we need to compare the highest priority element with the root, if the root has lesser priority, bubble it downward, repeat until there is no higher priority between the two children
but when does this loop end? 
    -When we have no children to compare to (if i*2+1 < n - 1)
*/
void PriorityQueue :: pop(){ //Edge cases
    if(size_ == 0) return;   // If its empty, return, nothing to pop
    if( data_.size() ==1){   // If there's only one element, just reduce size, return
        --this->size_;
        return;
    }
    swap(0,size_-1);
    --size_;  //Effecively reduces the size of the heap
    int i = 0; //Represents the root whose values we'll compare to with the children to appropriately bubble downwards
    int j = (i*2 )+1; //index of left child of new root
    int priority; //sentinel pointer to decide if we swap indices;
    while( j < size_){  //Keep looping till we have a valid left child to compare to, remeber that size_ marks the boundary of the end of the vector
        priority = i;
        if( type_ ==  maximum){
            if( j+1 >= size_){      //If there's only one left child, we only need to compare left child to root
                if( data_[j] > data_[priority]) //If the left child is has higher priority, swap
                    priority = j;
            
            }else{  //There are two children, compare children, get the highest priority, swap with parent if neccessary
                if( data_[j] > data_[priority])  priority = j;
                if( data_[j+1] > data_[priority]) priority = j + 1; //if right child has higher priority
            }

        }else{  //type_ is a min priority queue
            if(j+1 >= size_){
                if(data_[j] < data_[priority]) priority = j;
            }else{
                if( data_[j] < data_[priority]) priority = j;
                if( data_[j+1] < data_[priority]) priority = j+1;
            }
        }


        if( i != priority){ //If we've seen a canidate to swap (ie a value maximum or smaller) swap it
            swap(i, priority);
            i = priority;
            j = (i*2) +1;
        }else{  //if i == priority, means theres nothing to swap, so just break;
            break;
        }

    }
}


void PriorityQueue :: swap(int x, int y){
    int temp = data_[x];
    data_[x] = data_[y];
    data_[y] = temp;
    
}

void PriorityQueue :: heapSort(){
    while( size_ !=0){
        this -> pop();
    }
    std :: cout<<"Sorted Vector: "<<std :: endl;
    for( int i = 0; i< data_.size(); i++){
        std :: cout<<data_[i]<<" ";
    }
}

bool PriorityQueue :: empty(){
    return this->size_ == 0 ? true : false;
}

void PriorityQueue :: display(){
    while(size_ !=0){
        std :: cout<< this->front()<<" ";
        this -> pop();
    }
}

void PriorityQueue :: arrDisplay(){
    for( int el : data_){
        std :: cout<<el<<" ";
    }
}