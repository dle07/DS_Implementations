#include "StackArray.hpp"





template <typename xType>
StackArray<xType> :: StackArray(){

}


template <typename xType>
StackArray<xType> :: StackArray(const StackArray<xType> & a_stack){
    this->stackVector.clear();
    for( xType el : a_stack.stackVector){
        stackVector.push_back(el);
    }
}


template <typename xType>
void StackArray<xType> :: push(xType elem){
    this->stackVector.push_back(elem);
}


template <typename xType>
void StackArray<xType> :: pop(){
    this->stackVector.pop_back();
}


template <typename xType>
bool StackArray<xType> :: empty(){
    return this->stackVector.empty()? true: false;
}


template <typename xType>
xType StackArray<xType> :: top(){
    return this->stackVector.back();
}


template <typename xType>
int StackArray<xType> :: size(){
    return this->stackVector.size();
}