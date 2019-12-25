//
// Created by sean on 12/12/19.
//
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#ifndef DS_2_RECURSIVE_H
#define DS_2_RECURSIVE_H

class factory{
    public:
        typedef std::shared_ptr<factory> Ptr;
        static int fact(int in_val){
            if(in_val == 1) {
                return 1;
            }
            else{
               return in_val * fact(in_val-1);
            }
        }

        static void backwardstr(const std::string& in_str, int last){
            if(last >= 0){
              std::cout<< in_str.at(last) << std::endl;
              backwardstr(in_str, last-1);
            }
        }

        static int binarySearch(const std::vector<int> in_vec, int target , int first, int last) {
            if( first == last){
                return -1;
            }
            int idx = 0;
            int mid = (first + last)/2;

            if(target == in_vec[mid])
                return mid;

            if(target <= in_vec[mid]){
               idx = binarySearch(in_vec, target, first, mid);
            }

            else {
               idx = binarySearch(in_vec, target, mid , last);
            }
            return idx;
        }





    private:
};




#endif //DS_2_RECURSIVE_H
