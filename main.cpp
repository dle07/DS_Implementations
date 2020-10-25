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
using std :: string;
using std :: cout;
using std :: endl;
using std :: cin;


int main(){

    QueueList<int> myQueue;
    myQueue.enQueue(1);
    myQueue.deQueue();
    
    /*
    for( int i=1; i< 11 ; i++){
        myQueue.enQueue(i);
    }
    myQueue.deQueue();
    myQueue.display();
    */
    cout<<"Size: "<<myQueue.size()<<endl;
    cout<<"Hello World!"<<endl;
    return 0;
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
