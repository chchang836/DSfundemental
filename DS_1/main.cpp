#include <iostream>
#include "ToyBox.h"

int main() {
    //plainbox<int>::Ptr pb = std::make_shared<plainbox<int>>();
    //int x = 10;
    //auto value = pb->getItem();
    int in_x = 1;
    Color color = Color::BLACK;
    ToyBox<int>::Ptr tpb = std::make_shared<ToyBox<int>>(in_x, color);

    std::cout << "Hello, World!" << std::endl;

    ArrayBased<int>::Ptr aptr = std::make_shared<ArrayBased<int>>();
    aptr->AddElement(10);
    aptr->AddElement(20);
    aptr->AddElement(30);
    aptr->AddElement(40);
    aptr->AddElement(50);
    aptr->AddElement(60);
    aptr->AddElement(70);
    aptr->AddElement(80);
    aptr->AddElement(90);
    for(int i=0 ; i< aptr->getCountNum(); ++i){
        std::cout<< aptr->getItem(i)<<std::endl;
    }

    return 0;
}

