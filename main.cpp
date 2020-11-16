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

#include "./LinkedList/Node.hpp"
#include "./LinkedList/Node.cpp"
#include "./LinkedList/LinkedList.hpp"
#include "./LinkedList/LinkedList.cpp"
#include "./Queue/QueueList.hpp"
#include "./Queue/QueueList.cpp"
#include "./AVL_Tree/AvlTree.hpp"
using std :: string;
using std :: cout;
using std :: endl;
using std :: cin;


int main(){
    AvlTree<int> myTree;
    for( int i = 1; i< 11; i++){
        myTree.insert(i);
    }
    myTree.BFS();
    
}


/*



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
