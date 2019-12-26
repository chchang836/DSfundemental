//
// Created by sean on 12/24/19.
//
#include "list.h"
#include <memory>

#ifndef DS8_LINKLIST_H
#define DS8_LINKLIST_H

template <typename ItemType>
class Node{
public:
    typedef std::shared_ptr<Node> Ptr;
    typedef std::shared_ptr<Node<ItemType>> sharedPtr;

    Node(){};

    Node(const Node& node){ next = node;}

    Node(const ItemType& item){
        value = item;
    }

    Node(const ItemType& item, sharedPtr in_item){
        value = item;
        next = in_item;
    }

    void setNext(sharedPtr in_item){
        next = in_item;
    }

    ItemType getItem() const{
        return value;
    }

    sharedPtr getNext() const{
        return next;
    }

private:
    ItemType value;
    sharedPtr next;
};

template<class ItemType>
class Linklist : public ListInterface<ItemType>
{
    public:
      typedef std::shared_ptr<Linklist> Ptr;
      typedef std::shared_ptr<Node<ItemType>> sharedPtr;

      Linklist();

      bool isEmpty() const;

      int getLength() const;

      bool insert(int position, const ItemType& entry) throw();

      bool remove(int position);

      bool clean();

      ItemType getEntry(int position) const throw();

      ItemType replace(int position, const ItemType& entry){};

      ~Linklist(){
          clean();
      };

    private:

      sharedPtr headPtr;

      sharedPtr getNodeAt(int position) const;

      int itemCount;
      int maxItems;
};
#endif //DS8_LINKLIST_H
