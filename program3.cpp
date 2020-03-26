#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<time.h>
#include<chrono>
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

  ofstream output(argv[3],ofstream::out); //output file

  string x; //string from filex
  // Open filex for reading
  ifstream xfile(argv[1]);
  while(xfile >> x) {
  }
  //cout<<"X string: "<<x<<endl;
  sizex = x.size();
  string y; //string from filey
  //open filey for reading
  ifstream yfile(argv[2]);
  while(yfile >> y){
  }
  //cout<<"Y string: "<<y<<endl;
  sizey = y.size();
  xfile.close();
  yfile.close();
  matrix[sizex][sizey];
  matrix = new int *[sizex];
  for (int i = 0;i<sizex;i++){
    matrix[i] = new int[sizey];
  }
  //cout<<"got to this point"<<endl;
  //initialize everthing in row and colum 0 to 0
  for (int i=0;i<x.size();i++){
    matrix[i][0] = 0;
  }
  for(int j = 0;j<y.size();j++){
    matrix[0][j] = 0;
  }
  //initialize all other values to -1, indicating that they have not yet been updated
  for(int i = 1;i<x.size();i++){
    for (int j = 1; j<y.size();j++){
      matrix[i][j] = -1;
    }
  }
  auto start = chrono::high_resolution_clock::now(); //start time
  lcs_length(x,y,x.size()-1,y.size()-1);
  auto end = chrono::high_resolution_clock::now(); //end time
  auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end-start).count();//elapsed time
  output<<"Length: "<< matrix[x.size()-1][y.size()-1]<<endl;
  output<<"Time: "<<elapsed_time<<" microseconds"<<endl;
  return 0;
  output.close();
}
void lcs_length(string x, string y, int i, int j){//updates the table
  matrix[i][j] = lcs(x,y,i,j);
}
//helper function for lcs_length. Uses the recursive lcs algorigthtrm with memoization
int lcs(string x, string y,int i,int j){
  if (i<0||j<0){ //base case
    return 0;
  }
  if(matrix[i][j]!=-1){ //another base case
    return matrix[i][j];
  }
  if (matrix[i][j]== -1){ //recursive part
    if (x.at(i-1) == y.at(j-1)){
    return 1+ lcs(x,y, i-1,j-1);
    }
    else{
      return max(lcs(x,y,i-1,j),lcs(x,y,i,j-1));
    }
  }
}
