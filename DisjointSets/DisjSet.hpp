#ifndef DISJOINTSET_
#define DISJOINTSET_
#include <iostream>
#include <vector>
using namespace std;



class DisjSet{

    private:
    vector<int> s;  //This array will represent our set
    public:
    DisjSet(int n); //Constructor
    int find(int vertex);
    void unionize(int u, int v);        //cant write "union" for method name as it's a reserved keyword



};

#endif