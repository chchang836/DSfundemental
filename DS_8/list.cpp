//
// Created by sean on 12/23/19.
//
#include "list.h"
#include <string>

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int position, const ItemType &entry) {
    bool isAbleInsert = (position >= 0) &&
                        (position <= itemCount+1) && (position < maxItems);
    if(isAbleInsert) {
        for(int idx = itemCount; idx >= position; --idx){
               items[idx+1] = items[idx];
        }
        items[position] = entry;
        itemCount++;
    }
    return isAbleInsert;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const throw() {
    bool isAbleToGet = (position >= 0) && (position <= itemCount);
    if(isAbleToGet){
        return items[position];
    }
    else{
        std::string message = "get entry error";
        throw(message);
    }
}

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position,
                                      const ItemType& entry) throw() {
    bool isreplace = (position >= 1) && (position <= itemCount);
    if (isreplace) {
        ItemType oldItem = items[position];
        items[position] = entry;
        return oldItem;
    } else {
        std::string message = "get replaced entry error";
        throw(message);
    }
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
    bool isremove = (position >= 0) && (position < itemCount);
    if(isremove){
         for(int i = position; i <= itemCount; i++){
             items[i] = items[i+1];
         }
         itemCount--;
    }
    else{
        std::string message = "get removed entry error";
        throw(message);
    }
    return isremove;
}


template class ArrayList<int>;