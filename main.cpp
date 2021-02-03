#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <sstream>

#include "PriorityQueue/PriorityQueue.hpp"
#include "PriorityQueue/PriorityQueue.cpp"
#include "DisjointSets/DisjSet.hpp"
#include "DisjointSets/DisjSet.cpp"
#include "AVL_Tree/AvlTree.hpp"
using namespace std;

int main()
{
    DisjSet myTestSet(6);
    myTestSet.display();

    myTestSet.unionize(0,1);
    myTestSet.display();

    myTestSet.unionize(2,3);
    myTestSet.display();

    myTestSet.unionize(4,5);
    myTestSet.display();
    cout<<"==========================="<<endl;
    myTestSet.unionize(1,2);
    myTestSet.display();
    myTestSet.unionize(0,3);
    myTestSet.display();
    if(myTestSet.hasCycle()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    

    
    
    return 0;
}

/*
vector<int> temp;
    for( int i = 0; i <11; i++){
        temp.push_back(i);
    }
    PriorityQueue myQueue(temp, maximum);
    myQueue.heapSort();


LinkedList<int> myStringList;
    cout<<myStringList.getItemCount()<<endl;
    for( int i=0; i<10; i++){
        myStringList.addFront(i);
        cout<<"ItemCount: " <<myStringList.getItemCount()<<endl;
    }
    myStringList.print();
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    myStringList.removeFirstOccurrence(5);
    cout<<"ItemCount: " <<myStringList.getItemCount()<<endl;
    myStringList.addEnd(100);
    cout<<"ItemCount: " <<myStringList.getItemCount()<<endl;
    myStringList.addEnd(1011111);
    cout<<"ItemCount: " <<myStringList.getItemCount()<<endl;
    myStringList.removeEnd();
    cout<<"ItemCount: " <<myStringList.getItemCount()<<endl;
    myStringList.print();
    cout<<"ItemCount: " <<myStringList.getItemCount()<<endl;
    cout<<"Hello World!"<<endl;

    */
