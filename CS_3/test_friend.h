//
// Created by sean on 12/26/19.
//

#ifndef CS_3_TEST_FRIEND_H
#define CS_3_TEST_FRIEND_H
using namespace std;
#include <iostream>
#include <memory>
// forward declaration
class A {
 private:
   int number;
 public:
    A();
    // friend function declaration
    void print();
    int numA;
};

template <typename ItemType>
class temp{
    public:
      typedef std::shared_ptr<temp> Ptr;

      //typedef typename std::shared_ptr<temp<ItemType>> PtrType;
      //typedef std::shared_ptr<temp> Ptr;
      temp(int x, int y): x_(x), y_(y){};
      temp(){};

      void setX(int x){
          x_ = x;
      }

      void setY(int y){
          y_ = y;
      }

      ItemType getX(){
          return x_;
      }

      ItemType getY(){
          return y_;
      }

      friend void setupBoth(temp<ItemType>::Ptr& t, int x, int y);

    private:
      int x_;
      int y_;
};

# include<vector>
template <typename ItemType>
class maintemp{
  public:
    typedef std::shared_ptr<maintemp<ItemType>> Ptr;
    typedef typename temp<ItemType>::Ptr base_type;

    maintemp(){
        tmp = std::make_shared<temp<ItemType>>();
    };

    void test(std::vector<int>& invec) {
        typename std::vector<int>::iterator pp;
        for ( pp  = invec.begin(); pp != invec.end(); ++pp) {
            std::cout << *pp << "\n";
        }
    };
    base_type& func(int x, int y) {
        tmp->setX(x);
        tmp->setY(y);
        return tmp;
    };

    friend void setupBoth(base_type& t, int x, int y){
        t->x_ = x;
        t->y_ = y;
    }

  private:
    base_type tmp;
    int var;
};

// Class Declaration
class Point {
private:
    int x, y;
public:
    typedef std::shared_ptr<Point> Ptr;
    typedef std::shared_ptr<const Point> ConstPtr;

    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    friend std::ostream & operator<<(std::ostream & out, const Point & point);
    friend std::ostream & operator <<(std::ostream& out, Point::ConstPtr point);
};

class Base {
    public:
     Base(){};
     Base(int val): var_(val){};

     Base& operator =(const Base rhs){
         var_ = rhs.var_;
         return *this;
     }

    private:
     int var_;
};

class Integer {
private:
    int value;
public:
    Integer(int v) : value(v) { }
    Integer& operator++();
    Integer operator++(int);
    int getValue() {
        return value;
    }
};

#endif //CS_3_TEST_FRIEND_H

