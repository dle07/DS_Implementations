#ifndef DISJOINTSET_
#define DISJOINTSET_
#include <iostream>
#include <vector>
using namespace std;


/*
    A graph has a cycle if when a union method is called, the two vertices to be unionized belong to the same set.
    This means there exists a set of edges that already connect the two vertices, thus there's a cycle;
*/
class DisjSet{

    private:
    vector<int> s;  //This array will represent our set, 0 indexed
    bool cycle = false;
    vector<int> temp;
    public:
    DisjSet(int n); //Constructor

    int find(int vertex);
    void unionize(int u, int v);        //cant write "union" for method name as it's a reserved keyword

    int findSetSize(int v); //Returns the number of nodes in a particular set
    bool hasCycle();
    void display();  //helper test function



};

#endif