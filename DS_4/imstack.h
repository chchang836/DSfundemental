//
// Created by sean on 12/19/19.
//

#ifndef DS4_IMSTACK_H
#define DS4_IMSTACK_H

#include <memory>
using namespace std;

template<typename Item>
class StackInterface
{
 public:
    StackInterface(){};
    virtual bool isEmpty() const = 0;
    virtual bool push(const Item& input) = 0;
    virtual bool pop() = 0;
    virtual Item peek() const = 0;
    virtual ~StackInterface(){};
 private:
    int top;
};

template<class Item>
class ArrayStack : public StackInterface<Item>
{
public:
   ArrayStack(): top(-1){};

   bool isEmpty() const;

   bool push(const Item& entry);

   bool pop();

   Item peek() const;

private:
   static const int DEFAULT_SIZE = 100;
   Item items[DEFAULT_SIZE];
   int top;
};




#endif //DS4_IMSTACK_H
