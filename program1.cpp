

#include<iostream>
#include<fstream>
#include<string>
#include"Entry.h"
#include<vector>
#include<stdio.h>
#include<time.h>
#include<chrono>
using namespace std;
int lcs_length(string, string,char*);
//string my_str;
vector<char>my_str;
int main(int argc, char *argv[]) {

  ofstream output(argv[3],ofstream::out);//outptu file
   //longest common subsequence
  string x;
  // Open filex for reading
  ifstream xfile(argv[1]);
  while(xfile >> x) {
  }
  //cout<<"X string: "<<x<<endl;
  string y;
  //open filey for reading
  ifstream yfile(argv[2]);
  while(yfile >> y){
  }
  //cout<<"Y string: "<<y<<endl;
  xfile.close();
  yfile.close();
  auto start = chrono::high_resolution_clock::now();
  int test = lcs_length(x,y,argv[3]);
  auto end = chrono::high_resolution_clock::now();
  auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end-start).count();
//since the lcs is created backwards, it will be sent to output backwards, so that
//it will come out the right way
  if (x.length()<=10|| y.length()<=10){
    for (int i = my_str.size()-1;i>=0;i--){
      output<<my_str[i];
    }
    cout<<"Time: "<<elapsed_time<<" microseconds"<<endl;;
  }

  else{
    output<<"Length: "<<test<<endl;
    output<<"Time: "<<elapsed_time<<" microseconds"<<endl;
  }
  output.close();
  return 0;
}
int lcs_length(string s, string t, char*my_chr){
  ofstream output(my_chr,ofstream::out); //same output file
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

  //initialize all values in row 0 to 0
  for(unsigned long i = 0; i<s.length();i++){
      matrix[i][0].setVal(0);
  }
  //initialize all values in column 0 to 0
  for(unsigned long j = 0; j<t.length();j++){
    matrix[0][j].setVal(0);
  }
  for (unsigned long i = 1; i<s.length()+1;i++){
    for (unsigned long j=1; j<t.length()+1;j++){
      matrix[i][j].setDirection("n"); //initializes all directions to "n ", or "none"
      if(s.at(i-1) == t.at(j-1)){
        matrix[i][j].setVal(matrix[i-1][j-1].getVal()+1);
        matrix[i][j].setDirection("d");//sets direction to diagonal
        matrix[i][j].setChar(s.at(i-1));
      }
      else if(matrix[i-1][j].getVal()>=matrix[i][j-1].getVal()){
        matrix[i][j].setVal(matrix[i-1][j].getVal());
        matrix[i][j].setDirection("u");//sets direction to up
      }
      else if (matrix[i-1][j].getVal()<matrix[i][j-1].getVal()) {
        matrix[i][j].setVal(matrix[i][j-1].getVal());
        matrix[i][j].setDirection("l");//sets directino fo left
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

  //the following code prints out the table if both inputs are less than or
  //equal to 10 characters long:
  if (s.length()<=10||t.length()<=10){
    for (unsigned long i = 0; i<s.length()+1; i++){
      for(unsigned long j = 0; j<t.length()+1;j++){
        output<<matrix[i][j].getVal()<<","<<matrix[i][j].getDirection()<<" ";
      }
      output<<endl;
    }

  }


  s_index = s.length();//index of string x, initialized as the end
  t_index = t.length();//index of string y, initialized as the end
  retVal+=matrix[s_index][t_index].getVal();

//to find the longest common subsequence, we begin at the bottom right
//of the table:
  Entry current  = matrix[s_index][t_index];

  while (current.getDirection() != "n"){
    if (current.getDirection() == "d"){
      //go diagonal
      my_str.push_back(current.getChar()); //we add to the lcs since we went diagonal
      current = matrix[s_index-1][t_index-1];
      s_index--;
      t_index--;
      continue;
    }
    else if(current.getDirection() == "u"){
      //go up
      current = matrix[s_index-1][t_index];
      s_index--;
      continue;
    }
    else if(current.getDirection() == "l"){
      //go left
      current = matrix[s_index][t_index-1];
      t_index--;
      continue;
    }
  }

  return retVal;
}
