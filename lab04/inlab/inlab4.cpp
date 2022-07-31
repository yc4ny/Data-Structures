#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
using namespace std;
void sizeOfTest();
void outputBinary(unsigned int bin);
void overflow();
union S{
  unsigned int i;
  float f;
  int n;
  double d;
  char c;
  bool b;
}bar;
int main()
{
  bool b = true;
  char c = 'a';
  int i = 1;
  double d = 1.0;
  int* p = &i;
  cout << b <<endl;
  cout << c <<endl;
  cout << i <<endl;
  cout << d <<endl;
  cout << p <<endl;

  //inlab section from before ends

  //next inlab section begins
  int IntArray[10] = {1,2,3,4,5,6,7,8,9,10};
  char CharArray[10] = {'a','b','c','d','e','f','g','h','i','j'};
  int IntArray2D[6][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
  char CharArray2D[6][5] = {{'a','b','c','d','e'},{'f','g','h','i','j'}};
  return 0;
}
void sizeOfTest()
{
  int a = -4;
  unsigned int b = 5;
  float c= 72.0f;
  double d = 3.14;
  char e = 'a';
  bool f = true;
  int* g = NULL;
  char* h = NULL;
  double* i = NULL;
  cout<< "int " << sizeof(a) << endl;
  cout<< "unsigned int " << sizeof(b) << endl;
  cout<< "float " << sizeof(c) << endl;
  cout<< "double " << sizeof(d) << endl;
  cout<< "char " << sizeof(e) << endl;
  cout<< "bool " << sizeof(f) << endl;
  cout<< "int* " << sizeof(g) << endl;
  cout<< "char* " << sizeof(h) << endl;
  cout<< "double* " << sizeof(i) << endl;
}
void outputBinary(unsigned int bin)
{
  string s="";
  for(int i = 31; i>=0; i--){
    if(bin/(int)pow(2,i)!=0){
      s+="1";
      bin=bin-pow(2,i);
    }
    else{
      s+="0";
    }
    if(i%4==0)
      s+=" ";
  }
  cout<< s << endl;
}
void overflow()
{
  unsigned int n = UINT_MAX;
  cout << n << endl;
  cout << "The reason why an unsigned max int added by 1 is just 0 is because\
 the 32 bits  that were allocated for the max unsigned int was filled for the\
 max int and then  adding 1 caused an integer overflow and made the computer\
 delete all the bits  to handle the overflow and go back to 0"<<endl;
}
