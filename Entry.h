#ifndef ENTRY_H
#define ENTRY_H
#include<iostream>
class Entry{
private:
  int val;
  std::string direction;
public:
  int getVal();
  std::string getDirection();
  void setVal(int);
  Entry();
  void setDirection(std::string);
};
#endif
