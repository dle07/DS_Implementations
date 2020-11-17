#include "Node.hpp"




template <typename xType>
Node <xType> :: Node(): data_(nullptr),left_(nullptr),right_(nullptr){
    
}

template <typename xType>
Node <xType> :: Node(xType data)
:data_(data), left_(nullptr), right_(nullptr){

}