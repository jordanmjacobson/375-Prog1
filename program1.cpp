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
int lcs_length(string, string, string&);

int main(int argc, char *argv[]) {
  string my_str; //longest common subsequence
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
  int test = lcs_length(x,y,my_str);
  //cout<<my_str<<endl;
  cout<<endl<<"Length: "<<test<<endl;
  return 0;
}
int lcs_length(string s, string t, string &u){
  int retVal = 0;
  int s_index;
  int t_index;
  //vector<vector<Entry>> matrix;
  Entry matrix[s.length()+1][t.length()+1];
  u = "test";
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
  time_t begin;
  time_t end;
  time(&begin);
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
  for (unsigned long i = 0; i<s.length();i++){
    for (unsigned long j=0; j<t.length();j++){
      if(i==0||j==0){
        matrix[i][j] = 0;
        continue;
      }
    }
  }
  time(&end);
  double elapsed_time = difftime(end,begin);
  cout<<"Time: "<<elapsed_time<<" seconds"<<endl;
  for (unsigned long i = 0; i<s.length(); i++){
    for(unsigned long j = 0; j<t.length();j++){
      cout<<matrix[i][j].getVal()<<" ";
    }
    cout<<endl;
  }
  s_index = s.length()-1;
  t_index = t.length()-1;
  retVal+=matrix[s_index][t_index].getVal();
  //cout<<"got to this point";
  return retVal;
}
