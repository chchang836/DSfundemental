#include <iostream>
#include "imstack.h"


bool checkBrace(const std::string& in_str)
{
  ArrayStack<char> *astk = new ArrayStack<char>();
  for(char c: in_str) {
    if(c == '{')
      astk->push('{');
    else if(c == '}'){
      if(astk->isEmpty()){
          return false;
      }
      astk->pop();
    }
  }
  return astk->isEmpty();
}

bool checkbalance(const std::string& in_str)
{
    ArrayStack<char> *astk = new ArrayStack<char>();
    int fwd = false;
    for(char c: in_str) {
     if(c != '$' && !fwd ) {
        astk->push(c);
      }
      else if( c == '$'){
          fwd = true;
          continue;
      }
      else {
         if (astk->peek() == c) {
             astk->pop();
          }
         else{
             return false;
         }
      }
    }
    return astk->isEmpty();
}

int main() {
    std::string str ="{}{{{}}}}";
    std::cout<< checkBrace(str) <<std::endl;
    std::string str_in = "BA$A";
    std::cout<<"is empty "<<checkbalance(str_in) <<std::endl;
    return 0;
}