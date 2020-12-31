#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <vector>
#include <iostream>


using std :: vector;
/*
    Practicing my gained knowledge of binary heaps by implementing a application of the structure, priotity queues.
*/

enum type{
    greater,
    min
};
class PriorityQueue{

    private:
        std :: vector<int> data_;
        type type_; //
        int size_; 

    public:
    PriorityQueue();    //by default, the type is greater
    PriorityQueue(type type_);
    ~PriorityQueue();

    PriorityQueue (const PriorityQueue &target); //Deep copy constructor
    PriorityQueue(vector<int> vals); //Uses heapify to create this heap, takes linear time instead of O(nlogn) time if we were to insert elements in the heap one by one using a heap
    PriorityQueue(vector<int> vals, type type_); // Heapify and type of priority queue
    
    void swap(int x, int y);

    void enqueue(int val); //We want to insert to the
    int front();    //Returns the highest priority element
    void pop(); //Removes top element from the queue

    void heapSort();

};

#endif