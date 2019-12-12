//
// Created by sean on 12/11/19.
//

#include <iostream>
#include <memory>

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
  void setItem(Itemtype in_item){
      item = in_item;
  };

  Itemtype getItem(){
      return item;
  }
private:
};


