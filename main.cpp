#include <iostream>
#include "ToyBox.h"

int main() {
    plainbox<int>::Ptr pb = std::make_shared<plainbox<int>>();
    int x = 10;
    pb->setItem(x);
    auto value = pb->getItem();
    int in_x = 1;
    Color color = Color::BLACK;
    ToyBox<int>::Ptr tpb = std::make_shared<ToyBox<int>>(in_x, color);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

