//
// Created by sean on 12/19/19.
//

#include "imstack.h"
#include <cassert>

template <typename Item>
bool ArrayStack<Item>::isEmpty() const{
    return top == -1;
}

template<typename Item>
bool ArrayStack<Item>::push(const Item& entry){
    bool result = false;
    if( top < this->DEFAULT_SIZE){
        top++;
        items[top] = entry;
        result = true;
    }
    return result;
}

template<typename Item>
bool ArrayStack<Item>::pop() {
    bool result = false;
    if( top >= 0 ) {
       top--;
       result = true;
    }
    return result;
}

template<typename Item>
Item ArrayStack<Item>::peek() const{
    if(top >= 0){
        return items[top];
    }
    assert(isEmpty());
}

template class ArrayStack<char>;



