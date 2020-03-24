#ifndef ENTRY_H
#define ENTRY_H
#include<iostream>
class Entry{
private:
  int val;
  std::string direction;
  char c;
public:
  int getVal();
  std::string getDirection();
  void setVal(int);
  Entry();
  void setDirection(std::string);
  char getChar();
  void setChar(char&);
};
#endif
