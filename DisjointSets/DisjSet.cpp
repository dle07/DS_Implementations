#include "DisjSet.hpp"




DisjSet :: DisjSet(int n){
    this->s = vector<int>(n,-1);
}

int DisjSet :: find(int vertex){
    return this->s[vertex];
}

/*
    In our array repsentation of a disjoint set, the indices represent each vertex
    Each element or value associated with a vertex is either negative or positive
        -If it's positive this means that the vertex belongs to a set of itself
        -If it's negative
            -If its a -1 it means that the vertex hasn't been added to a certain set and belongs to itself currently
            -If the negative number is less than -1, it means its the head of a set

*/

void DisjSet ::  unionize(int v, int u){  //Union of two head of sets
    
    if( s[v] < s[u]){
        
    }else{

    }  
}