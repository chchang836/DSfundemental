//
// Created by sean on 12/24/19.
//
#include "list.h"
#include <memory>

#ifndef DS8_LINKLIST_H
#define DS8_LINKLIST_H

template <typename Itemtype>
class Node{
public:
    typedef std::shared_ptr<Node> Ptr;
    Node(){};

    Node(const Node& node){ next = node;}

    Node(const Itemtype& item){
        value = item;
    }

    Node(const Itemtype& item, Node<Itemtype>* in_item){
        value = item;
        next = in_item;
    }

    void setNext(Node<Itemtype>* in_item){
        next = in_item;
    }

    Itemtype getItem() const{
        return value;
    }

    Node<Itemtype>* getNext() const{
        return next;
    }

private:
    Itemtype value;
    Node<Itemtype>* next;
};

template<class ItemType>
class Linklist : public ListInterface<ItemType>
{
    public:
      typedef std::shared_ptr<Linklist> Ptr;

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
      Node<ItemType>* headPtr;
      Node<ItemType>* getNodeAt(int position) const;
      int itemCount;
      int maxItems;

};
#endif //DS8_LINKLIST_H
