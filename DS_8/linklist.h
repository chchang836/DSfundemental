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
    typedef std::shared_ptr<Node<ItemType>> Ptr;

    Node(){};

    Node(const Node& node){ next = node;}

    Node(const ItemType& item){
        value = item;
    }

    Node(const ItemType& item, const Node::Ptr& in_item){
        value = item;
        next = in_item;
    }

    void setNext(const Node::Ptr& in_item){
        next = in_item;
    }

    ItemType getItem() const{
        return value;
    }

    Node::Ptr getNext() const{
        return next;
    }

private:
    ItemType value;
    Node::Ptr next;
};

template<class ItemType>
class Linklist : public ListInterface<ItemType>
{
    public:
      typedef std::shared_ptr<Linklist<ItemType>> Ptr;
      typedef std::shared_ptr<Node<ItemType>> sharedPtr;

      Linklist();

      Linklist(const Linklist::Ptr inList) {
          this->itemCount = inList->itemCount;
          this->maxItems = inList->maxItems;
          int idx = 0;
          while(idx < inList->getLength()){
              this->insert(idx, inList->getEntry(idx));
              idx++;
          }
      }

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

      bool isEqualto(const Linklist::Ptr& inList) const throw() {
          auto crt_ptr = headPtr;
          auto rhs_prt = inList->headPtr;
          if(this->itemCount != inList->itemCount){
              std::string msg = "number of entries are not matched";
              throw (msg);
          }
          while(crt_ptr || rhs_prt){
              if( crt_ptr->getItem() != rhs_prt->getItem()){
                 return false;
              }
              crt_ptr = crt_ptr->getNext();
              rhs_prt = rhs_prt->getNext();
          }
          return true;
      }

    bool friend operator==(const Linklist::Ptr& lhs,
                           const Linklist::Ptr& inlist){
        return lhs->isEqualto(inlist);
    }



private:

      sharedPtr headPtr;
      sharedPtr getNodeAt(int position) const;

      int itemCount;
      int maxItems;
};



#endif //DS8_LINKLIST_H
