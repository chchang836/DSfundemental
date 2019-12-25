//
// Created by sean on 12/12/19.
//
# include <iostream>
# include <memory>
# include <vector>
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename Itemtype>
class Node{
 public:

    Node(){};

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

using namespace std;
template <typename Itemtype>
class LinkedBag {
 public:
    typedef shared_ptr<LinkedBag> Ptr;
    LinkedBag(){};

    LinkedBag(const LinkedBag<Itemtype>& inBag){
        this->crt_item = inBag.crt_item;
        Node<Itemtype>* node = inBag.headPrt;
        if(node == nullptr){
          headPrt = nullptr;
        }
        else{
            Node<Itemtype>* tmp_node = inBag.headPrt;
            int idx = 0;
           while((idx < this->crt_item) && tmp_node != nullptr){
               Node<Itemtype>* node = new Node<Itemtype>(tmp_node->getItem());
               node->setNext(headPrt);
               headPrt = node;
               tmp_node = tmp_node->getNext();
               idx++;
           }
        }
    }

    virtual ~LinkedBag(){};

    bool add(const Itemtype& input) {
        Node<Itemtype>* node = new Node<Itemtype>(input);
        node->setNext(headPrt);
        headPrt = node;
        crt_item++;
    }

    vector<Itemtype> toVector() {
       int idx = 0;
       std::vector<Itemtype> vec;
       Node<Itemtype>* tmp_node = headPrt;
       while((idx < crt_item) && (tmp_node != nullptr)){
         vec.push_back(tmp_node->getItem());
         tmp_node = tmp_node->getNext();
         idx++;
       }
       return std::move(vec);
    }

    int isEmpty(){
      return crt_item == 0;
    }

    int getCrtSize(){
      return crt_item;
    }

    int getFrequency(const Itemtype& item) {
        int idx = 0;
        int count = 0;
        Node<Itemtype>* tmp_node = headPrt;
        while((idx < crt_item) && (tmp_node != nullptr)){
            if(item == tmp_node->getItem()){
                count++;
            }
            tmp_node = tmp_node->getNext();
            idx++;
        }
        return count;
    }

    Node<Itemtype>* getPointer(const Itemtype& item){
        int idx = 0;
        bool found = false;
        Node<Itemtype>* tmp_node = headPrt;
        while((idx < crt_item) && (tmp_node != nullptr)) {
          if( item == tmp_node->getItem()) {
              return tmp_node;
          }
          tmp_node = tmp_node->getNext();
          idx++;
        }
    }

    bool clear() {
        Node<Itemtype>* tmp_node = headPrt;
        while(crt_item != 0 && tmp_node != nullptr){
            headPrt = headPrt->getNext();
            tmp_node->setNext(nullptr);
            delete tmp_node;
            tmp_node = headPrt;
            crt_item--;
        }
        return crt_item == 0;
    }
 private:
    // initial head prt
    Node<Itemtype>* headPrt;
    int crt_item;
};




#endif //DS_3_LINKEDLIST_H
