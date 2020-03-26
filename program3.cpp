#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<time.h>

using namespace std;
//string my_str;
int lcs(string,string,int,int);
void lcs_length(string,string,int,int);
//int matrix[][];
int * *  matrix = nullptr;
int main(int argc, char *argv[]) {
   //table dimensions
  int sizex;
  int sizey;

  string x; //string from filex
  // Open filex for reading
  ifstream xfile(argv[1]);
  while(xfile >> x) {
  }
  cout<<"X string: "<<x<<endl;
  sizex = x.size();
  string y; //string from filey
  //open filey for reading
  ifstream yfile(argv[2]);
  while(yfile >> y){
  }
  cout<<"Y string: "<<y<<endl;
  sizey = y.size();
  xfile.close();
  yfile.close();
  matrix[sizex][sizey];
  matrix = new int *[sizex];
  for (int i = 0;i<sizex;i++){
    matrix[i] = new int[sizey];
  }
  cout<<"got to this point"<<endl;
  for (int i=0;i<x.size();i++){
    matrix[i][0] = 0;
  }
  for(int j = 0;j<y.size();j++){
    matrix[0][j] = 0;
  }
  for(int i = 1;i<x.size();i++){
    for (int j = 1; j<y.size();j++){
      matrix[i][j] = -1;
    }
  }
  lcs(x,y,x.size()-1,y.size()-1);
  cout<<"LCS: "<< matrix[x.size()-1][y.size()-1]<<endl;
  return 0;
}
void lcs_length(string x, string y, int i, int j){
  matrix[i][j] = lcs(x,y,i,j);
}
int lcs(string x, string y,int i,int j){
  if (i<0||j<0){
    return 0;
  }
  if(matrix[i][j]!=-1){
    return matrix[i][j];
  }
  if (matrix[i][j]== -1){
    if (x.at(i-1) == x.at(j-1)){
    return 1+ lcs(x,y, i-1,j-1);
    }
    else{
      return max(lcs(x,y,i-1,j),lcs(x,y,i,j-1));
    }
  }
}
