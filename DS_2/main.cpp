#include <iostream>
#include "recursive.h"

int main() {
    std::string str ("Cat Cat");
    std::cout <<"string size "<< str.size() <<std::endl;

//    for (unsigned i=0; i< str.length(); ++i){
//        std::cout << str.at(i) <<std::endl;
//    }

    factory::backwardstr(str, str.size()-1);

    std::vector<int> in_vec {1,3,4,5,8,10,11,13,15,20};

    factory::binarySearch(in_vec, 15, 0, in_vec.size()-1);

    std::vector<int> in_vec2 {1,3,4,5};
    factory::maxinarray(in_vec2,0, in_vec2.size()-1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}