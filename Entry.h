#ifndef ENTRY_H
#define ENTRY_H
#include<iostream>
class Entry{
private:
  int val;
  std::string direction;
  char c;
public:
  int getVal(); //returns value
  std::string getDirection(); //returns direction
  void setVal(int);//set value
  Entry();//constructor
  void setDirection(std::string);//set direction
  char getChar();//returns character
  void setChar(char&);//sets character
};
#endif
