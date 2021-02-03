#include "DisjSet.hpp"


/*
    -1 -1  -1 -1 -1 
    0   1   2  3  4 
    1   4   3   -2  -3
    0   1   2   3   4 
*/

DisjSet :: DisjSet(int n){
    this->s = vector<int>(n,-1);
}
//This is where compresison will take place, we travel up to the head of the set and add vertices that don't point directly to the head along our way
//If s[vertex] >= 0 it means we have a child
//if s[vertex] <0 it means its the head, the loop will end there, thus vertex will represent the node where its the head
int DisjSet :: find(int vertex){    

    while(s[vertex] >=0){ //Belongs to a parent,
        temp.push_back(vertex);
        vertex = s[vertex];
    }
    for(int index : temp){  //path compression
        s[index] = vertex;
    }

    temp.clear();
    return vertex;
}

/*
    In our array repsentation of a disjoint set, the indices represent each vertex
    Each element or value associated with a vertex is either negative or positive
        -If it's positive this means that the vertex belongs to a set of itself
        -If it's negative
            -If its a -1 it means that the vertex hasn't been added to a certain set and belongs to itself currently
            -If the negative number is less than or equal to-1, it means its the head of a set

*/


//We always assume v and u arent heads of a set, thus we must find the actual head using out find method,
// Smaller to higher (union by rank), we attach the smaller tree to the larger one because when we attach a tree to another, the nodes in the sub tree will increase by one, 
//thus we should minimize our sum height by attaching the smaller tree
void DisjSet ::  unionize(int v, int u){ 
    if( v < 0 || v >= s.size() || u < 0 || u >= s.size()) return; //No valid vertex

    v = find(v);
    u = find(u);
    
    if(v == u){  //If they're of the same set, return
        this -> cycle = true; 
        return;
    }


    if( s[v] <  s[u] ){ //more elements in v than u (These are negative integers we're deeaking with), set v to join with u
    s[v] += s[u];  //Negative + negative == negative
    s[u] = v; //Redirection
    }else{
        s[u] += s[v];
        s[v] = u;
    }
}

int DisjSet :: findSetSize(int v){
    if( v < 0 || v >= s.size()) return -1; //Invalid input;
    return s[find(v)];
}

bool DisjSet :: hasCycle(){
    return this->cycle;
}

void DisjSet :: display(){
    for(int el: s){
        cout<<el<<" ";
    }
    cout<<endl;
}