//
// Created by sean on 12/26/19.
//
#include "test_friend.h"
#include <iostream>
using namespace std;
A::A(){
    numA = 10;
};

void A::print() {
    std::cout << "print " << std::endl;
}

//std::ostream& operator << (std::ostream& out, const Point& point){
//   out << "(" << point.x <<","<< point.y<<")";
//   return out;
//}
//
//std::istream& operator >> (std::istream& in, Point& point){
//    std::cout << "Enter x and y" << std::endl;
//    in >> point.x >> point.y;
//    return in;
//}

Point::Point(int inX, int inY){
    x = inX;
    y = inY;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

ostream& operator<<(std::ostream& out, const Point & point) {
    out << "(" << point.getX() << "," << point.x << ")";
    return out;
}

ostream& operator<<(std::ostream & out, Point::ConstPtr& point) {
    out << "(" << point->getX() << "," << point->getY() << ")";
    return out;
}


// Pre-increment Operator
Integer& Integer::operator++(){
    value++;
    return *this;
}

// Post-increment Operator
Integer Integer::operator++(int){
    const Integer old(*this);
    ++(*this);
    return old;
}

