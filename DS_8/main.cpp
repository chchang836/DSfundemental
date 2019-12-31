#include <iostream>
#include "list.h"
#include "linklist.h"
using namespace std;

class Distance {
private:
    int feet;             // 0 to infinite
    int inches;           // 0 to 12
public:
    // required constructors
    typedef std::shared_ptr<Distance> Ptr;
    Distance() {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }
    void operator = (const Distance::Ptr &D ) {
        feet = D->feet;
        inches = D->inches;
    }

    Distance::Ptr friend operator+(const Distance::Ptr &lhs, const Distance::Ptr &rhs){
        Distance::Ptr tmp = std::make_shared<Distance>();
        tmp->feet = lhs->feet + rhs->feet;
        tmp->inches = lhs->inches + rhs->inches;
        return tmp;
    }

   void operator+=(const Distance::Ptr& rhs){
        this->feet += rhs->feet;
        this->inches += rhs->inches;
    }

    // method to display distance
    void displayDistance() {
        cout << "F: " << feet <<  " I:" <<  inches << endl;
    }
};

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
//    ast->remove(0);
//   Distance::Ptr d1;
   std::shared_ptr<Distance> d1 = std::make_shared<Distance>(10,2);
   std::shared_ptr<Distance> d2 = std::make_shared<Distance>(3,2);

   Distance d3(10,2);
   Distance d4(3,2);
   d3 += d2;
   std::shared_ptr<Distance> ds = std::make_shared<Distance>(d3);
    Linklist<int>::Ptr llst = std::make_shared<Linklist<int>>();
    llst->insert(0,0);
    llst->insert(1,1);
    llst->insert(2,2);
    llst->insert(3,3);
    llst->insert(4,4);


//    Linklist<int>::Ptr lrst = std::make_shared<Linklist<int>>();
//    lrst->insert(0,0);
//    lrst->insert(1,1);
//    lrst->insert(2,2);
//    lrst->insert(3,3);
//    lrst->insert(4,4);

    //Linklist<int>::Ptr lrst;
    Linklist<int>::Ptr lrst  = std::make_shared<Linklist<int>>(llst);
    std::cout<<"" ;

//    if(llst == (lrst)){
//       std::cout<<"equal "<<std::endl;
//    }

//    llst->clean();
//    std::cout<< llst->isEmpty() << std::endl;
//    std::cout<<""<<std::endl;
    return 0;
}