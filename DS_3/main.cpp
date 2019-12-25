#include <iostream>
#include "linkedlist.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Node<int>* node = new Node<int>(2);
    node->setNext(new Node<int>(4));
    node->getNext()->setNext(new Node<int>(6));

    LinkedBag<int>* lbg = new LinkedBag<int>();
    lbg->add(2);
    lbg->add(4);
    lbg->add(5);
    lbg->add(3);
    lbg->add(2);
    lbg->add(2);

    LinkedBag<int>* lbg2 = new LinkedBag<int>(*lbg);
    std::cout<<"";
//    auto vec = lbg->toVector();
//    auto freq = lbg->getFrequency(2);
//    lbg->clear();


    std::cout<<"value "<<std::endl;
    return 0;
}