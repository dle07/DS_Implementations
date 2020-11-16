#include "Node.hpp"




template <typename xType>
Node <xType> :: Node(): data_(nullptr),left(nullptr),right(nullptr){
    
}

template <typename xType>
Node <xType> :: Node(xType data)
:data_(data), left(nullptr), right(nullptr){

}