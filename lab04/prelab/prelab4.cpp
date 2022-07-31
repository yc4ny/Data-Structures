#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
using namespace std;
void sizeOfTest();
void outputBinary(unsigned int bin);
void overflow();
int main()
{
  int num;
  sizeOfTest();
  cin >> num;
  outputBinary(num);
  overflow();
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
  unsigned int n = UINT_MAX + 1;
  cout << n << endl;
  cout << "The reason why an unsigned max int added by 1 is just 0 is because\
 the 32 bits  that were allocated for the max unsigned int was filled for the\
 max int and then  adding 1 caused an integer overflow and made the computer\
 delete all the bits  to handle the overflow and go back to 0"<<endl;
}
