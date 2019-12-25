//
// Created by sean on 12/24/19.
//
#include "linklist.h"
template<class ItemType>
Linklist<ItemType>::Linklist(): headPtr(nullptr), itemCount(0){
}

template <class ItemType>
bool Linklist<ItemType>::isEmpty() const{
   return itemCount == 0;
}

template <class ItemType>
int Linklist<ItemType>::getLength() const {
    return itemCount;
}

template <class ItemType>
Node<ItemType>* Linklist<ItemType>::getNodeAt(int position) const {
    Node<ItemType>* crtPtr = headPtr;
    int counter = 0;
    while(crtPtr != nullptr) {
        if(counter == position){
            return crtPtr;
        }
        counter++;
        crtPtr = crtPtr->getNext();
    }
    if(crtPtr->getNext() == nullptr){
        return headPtr;
    }
}

template <class ItemType>
ItemType Linklist<ItemType>::getEntry(int position) const throw() {
    bool ableToGet = (position >= 0) && (position <= itemCount);
    if(ableToGet){
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
    }
    else{
        std::string msg = "incorrected position input";
        throw(msg);
    }
}

template<class ItemType>
bool Linklist<ItemType>::insert(int position, const ItemType &entry) throw(){
    bool ableToInsert = (position >= 0) && (position <= itemCount);
    if(ableToInsert){
        // if it is empty
        if(headPtr == nullptr){
          headPtr = new Node<ItemType>(entry);
        }
        else{
          auto prePrt = getNodeAt(position-1);
          auto nxtPtr = prePrt->getNext();
          Node<ItemType>* nodePtr = new Node<ItemType>(entry, nxtPtr);
          prePrt->setNext(nodePtr);
        }
        itemCount++;
    }
    else{
        std::string msg = "incorrected position input";
        throw(msg);
    }
    return ableToInsert;
}

template<class ItemType>
bool Linklist<ItemType>::remove(int position){
    bool ableToRemove = (position >= 0) && (position <= itemCount);
    if(ableToRemove){
        if(itemCount == 1){
            //auto cur_ptr = headPtr;
            headPtr = headPtr->getNext();
            itemCount--;
        }
        else {
            auto pre_ptr = getNodeAt(position - 1);
            auto crt_ptr = pre_ptr->getNext();
            pre_ptr->setNext(crt_ptr->getNext());
            crt_ptr->setNext(nullptr);
            itemCount--;
            crt_ptr = nullptr;
            delete crt_ptr;
        }
    }
    else{
        std::string msg = "incorrected position input";
        throw(msg);
    }
    return ableToRemove;
}

template<class ItemType>
bool Linklist<ItemType>::clean() {
    while(itemCount){
        remove(1);
    }
}

template class Linklist<int>;
