#include <iostream>
#include "list.h"
#include "linklist.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
//    ArrayList<int>::Ptr ast = std::make_shared<ArrayList<int>>();
//    ast->insert(0,0);
//    ast->insert(1, 1);
//    ast->insert(2,2);
//    ast->insert(3,3);
//    ast->insert(4,4);
//    ast->insert(2,10);
//    ast->insert(5,11);
//
//    ast->remove(3);
//    ast->remove(2);
//    ast->remove(1);
//    ast->remove(0);
//    ast->remove(0);
//    ast->remove(0);
//    ast->remove(0);
//    ast->remove(0);;
    Linklist<int>::Ptr llst = std::make_shared<Linklist<int>>();
    Node<int>::Ptr ppt;
    llst->insert(0,0);
    llst->insert(1,1);
    llst->insert(2,2);
    llst->insert(3,3);
    llst->insert(4,4);
    llst->insert(5,5);
    llst->insert(4,20);
    llst->clean();
    std::cout<< llst->isEmpty() << std::endl;
    std::cout<<""<<std::endl;
    return 0;
}