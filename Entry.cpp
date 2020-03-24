#include"Entry.h"
int Entry::getVal(){return this->val;}
std::string Entry::getDirection(){return this->direction;}
void Entry::setVal(int n){this->val = n;}
void Entry::setDirection(std::string s){this->direction = s;}
Entry::Entry(){
  this->val = 0;
  this->direction = "none";
}
