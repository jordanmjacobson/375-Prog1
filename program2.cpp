
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<time.h>

using namespace std;
//string my_str;
int lcs(string,string,int,int);
int main(int argc, char *argv[]) {

  ofstream output(argv[3],ofstream::out);//output file
  string x; //strint from filex
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
  output<<"Length: "<<lcs(x,y,x.length()-1,y.length()-1)<<endl;
  auto end = chrono::high_resolution_clock::now();
  auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end-start).count();
  output<<"Time: "<<elapsed_time<<" microseconds"<<endl;
  return 0;
  output.close();
}

int lcs(string x,string y,int i,int j){
  if (i<0||j<0){
    return 0;
  }
  else if(x.at(i) == y.at(j)){
    return 1+lcs(x,y,i-1,j-1);
  }
  else{
    return max(lcs(x,y,i-1,j),lcs(x,y,i,j-1));
  }
}
