/* Example
 * Parsing Branch Traces
 */

#include<iostream>
#include<fstream>
#include<string>
#include"Entry.h"
#include<vector>
#include<stdio.h>
#include<time.h>

using namespace std;
int lcs_length(string, string);
//string my_str;
vector<char>my_str;
int main(int argc, char *argv[]) {
   //longest common subsequence
  string x;
  // Open filex for reading
  ifstream xfile(argv[1]);
  while(xfile >> x) {
  }
  cout<<"X string: "<<x<<endl;
  string y;
  //open filey for reading
  ifstream yfile(argv[2]);
  while(yfile >> y){
  }
  cout<<"Y string: "<<y<<endl;
  xfile.close();
  yfile.close();
  int test = lcs_length(x,y);

  for (int i = my_str.size()-1;i>=0;i--){
    cout<<my_str[i];
  }

  cout<<endl<<"Length: "<<test<<endl;
  return 0;
}
int lcs_length(string s, string t){
  int retVal = 0;
  int s_index;
  int t_index;
  //vector<vector<Entry>> matrix;
  Entry matrix[s.length()+1][t.length()+1];
  //my_str = "";
  /*for (unsigned long i = 0; i<s.length();i++){
    matrix[i][0].setVal(0);
    for (unsigned long j = 0; j<t.length();j++){
      //cout<<"got to this point"<<endl;

      matrix[0][j].setVal(0);
      //cout<<matrix[i][j].getVal()<<endl;
    }

  }*/
  //matrix - normal index, strings are minus 1
  //
  //time_t begin;
  //time_t end;
  //time(&begin);
  /*for (unsigned long i = -1; i<s.length()+1;i++){
    for(unsigned long j = -1; j<t.length()+1;j++){
      if (i == -1 || j == -1){
        matrix[i+1][j+1].setVal(0);
        continue;
      }
      if (s.at(i) == t.at(j)){
        matrix[i][j].setVal(matrix[i][j].getVal());
        matrix[i][j].setDirection("diagonal");
      }
      else if (matrix[i-1][j-1].getVal() >=matrix[i][j].getVal()){
        matrix[i][j].setVal(matrix[i][j+1].getVal());
        matrix[i][j].setDirection("up");
      }
      else if (matrix[i][j].getVal()<matrix[i+1][j].getVal()){
        matrix[i+1][j+1].setVal(matrix[i+1][j].getVal());
        matrix[i+1][j+1].setDirection("left");
      }
      //cout<<matrix[i][j].getVal()<<" ";
    }
    //cout<<endl;
  }*/
  for(unsigned long i = 0; i<s.length();i++){
      matrix[i][0].setVal(0);
  }
  for(unsigned long j = 0; j<t.length();j++){
    matrix[0][j].setVal(0);
  }
  for (unsigned long i = 1; i<s.length()+1;i++){
    for (unsigned long j=1; j<t.length()+1;j++){
      matrix[i][j].setDirection("n");
      if(s.at(i-1) == t.at(j-1)){
        matrix[i][j].setVal(matrix[i-1][j-1].getVal()+1);
        matrix[i][j].setDirection("d");
        matrix[i][j].setChar(s.at(i-1));
      }
      else if(matrix[i-1][j].getVal()>=matrix[i][j-1].getVal()){
        matrix[i][j].setVal(matrix[i-1][j].getVal());
        matrix[i][j].setDirection("u");
      }
      else if (matrix[i-1][j].getVal()<matrix[i][j-1].getVal()) {
        matrix[i][j].setVal(matrix[i][j-1].getVal());
        matrix[i][j].setDirection("l");
      }
      //cout<<"i: "<<i<<" j: "<<j<<endl;
    }
  }
  //time(&end);
  //double elapsed_time = difftime(end,begin);
  //cout<<"Time: "<<elapsed_time<<" seconds"<<endl;
  //cout<<"got to this point";
  //cout<<"debug";
  //cout<<s.length()<<endl;
  //cout<<t.length()<<endl;
  for (unsigned long i = 0; i<s.length()+1; i++){
    for(unsigned long j = 0; j<t.length()+1;j++){
      cout<<matrix[i][j].getVal()<<","<<matrix[i][j].getDirection()<<" ";
    }
    cout<<endl;
    //cout<<i<<","<<endl;
  }
  //cout<<"got to this point 1 ";
  s_index = s.length();
  t_index = t.length();
  retVal+=matrix[s_index][t_index].getVal();
  //cout<<"got to this point 2";
  Entry current  = matrix[s_index][t_index];
  //cout<<"got to this point 3";
  while (current.getDirection() != "n"){
    if (current.getDirection() == "d"){
      my_str.push_back(current.getChar());
      current = matrix[s_index-1][t_index-1];
      s_index--;
      t_index--;
      continue;
    }
    else if(current.getDirection() == "u"){
      current = matrix[s_index-1][t_index];
      s_index--;
      continue;
    }
    else if(current.getDirection() == "l"){
      current = matrix[s_index][t_index-1];
      t_index--;
      continue;
    }
  }
  //cout<<"got to this point";
  return retVal;
}
