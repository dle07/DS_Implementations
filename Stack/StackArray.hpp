#ifndef STACK_ARRAY_
#define STACK_ARRAY_
#include <vector>


/*
    First in, last out , FILOOOooooooooooo
    A Stack is a first in, last out structure. The user can push an item to the stack, 
    and items can only leave the stack from the "top" or the "start", hence FILO.
    All operations should be constant O(1)
    This stack implementation will be based on a dynamic array, specifically using STL's Vector<T>
    This is arguably the easiest trivial Data Structure Implementation, as the logic is simple, 
    and there are basically no edge cases
*/
template<typename xType>
class StackArray{

    private:
    std :: vector<xType> stackVector;

    public:
    StackArray();
    StackArray( const StackArray<xType> &a_stack );
    ~StackArray();
    void push(xType elem);
    void pop();
    bool empty();
    xType top();
    int size();

};


#endif