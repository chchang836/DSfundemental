//
// Created by sean on 12/11/19.
//

#include <iostream>
#include <memory>
#include <cstdint>
#include <cstring>

//struct LocalVar{
//    int value;
//    void func(){
//        std::cout <<" local_var " <<std::endl;
//    }
//};
//
//class Y {
//public:
//    LocalVar lvar;
//};
//
//template<class T>
//class X {
//    typename T::Y i;
//public:
//    void f() { i.lvar.func();}
//};

using namespace std;
template <typename Itemtype>
class plainbox {
public:
  typedef std::shared_ptr<plainbox> Ptr;
  plainbox(){};
  plainbox(const Itemtype in_item){ item = in_item;}

  Itemtype item;

  virtual void setItem(Itemtype in_item) = 0;

  Itemtype getItem(){
      return item;
  }

private:
};

template <typename Itemtype>
class ArrayBased {
 public:
   typedef std::shared_ptr<ArrayBased> Ptr;
   ArrayBased() : countItem(0), maxItem(DEFAULT_CAPACITY){
       items = new Itemtype[DEFAULT_CAPACITY];
   };

   bool AddElement(Itemtype in_item) {
     if(this->countItem < maxItem ){
       items[this->countItem] = in_item;
       this->countItem ++;
       return true;
      }

     else {
         Itemtype* newarray;
         newarray = new Itemtype[maxItem];
         std::memcpy(newarray, items, maxItem*sizeof(int));
         items = new Itemtype[2*maxItem];
         std::memcpy(items, newarray, maxItem*sizeof(int));
         delete newarray;
         maxItem = 2* maxItem;
         items[countItem] = in_item;
         countItem++;
     }
     return false;
   }

   int getItem(int idx) {
       if( idx < countItem) {
           return items[idx];
       }
       else{
           return -999;
       }
   }

   int getCountNum(){return countItem; }

   bool isEmpty(){
       return this->countItem == 0;
   }

   int getCurrentSize() {
       return this->countItem;
   }

   int getFrequency(const Itemtype entity){
       int crt_idx = 0;
       int frequency = 0;
       while (crt_idx < maxItem){
           if( items[crt_idx] == entity){
               frequency++;
           }
           crt_idx++;
       }
       return frequency;
   }

   bool contains(const Itemtype in_entity){
       return getFrequency(in_entity) > 0 ;
   }

   int getIndexof(const Itemtype in_entity){
    bool isFound = false;
    int crt_idx = 0;
    while( !isFound && crt_idx < this->countItem ){
        isFound = in_entity == items[crt_idx];
        if(isFound){
            return crt_idx;
        }
        crt_idx++;
     }
   }

   int getIndexofRec(const Itemtype in_entity, int& crt_idx) const {
       if(items[crt_idx] == in_entity){
           return crt_idx;
       }
       if( crt_idx < this->countItem){
           crt_idx++;
           return getIndexofRec(in_entity, crt_idx);
       }
       else {
           return -1;
       }
   }

    void countFrequency(const Itemtype in_entity, int& idx, int& frequency) const {
        if(idx < maxItem){
            if(items[idx] == in_entity){
                frequency++;
                idx++;
                countFrequency(in_entity, idx, frequency);
            }
        }
        return;
    }

  int getFrequencyofRec(const Itemtype in_entity) const {
       int idx = 0;
       int frequency = 0;
       countFrequency(in_entity, idx, frequency);
       return frequency;
  }

 private:
    int countItem;
    int maxItem ;
    static const int DEFAULT_CAPACITY = 2;
    Itemtype* items;

};





