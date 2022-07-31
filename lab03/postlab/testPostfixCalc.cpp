#include <iostream>
#include "postfixCalculator.h"
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
int main() {
  PostFixCalculator p;
  while(cin.good()){
    string str;
    cin >> str;
    string num="";
      if(isdigit(str[0])){
        p.pushNum(stoi(str));
      }
      else if(isdigit(str[0])== false){
	int i;
	if(str[0]=='+')
	  p.add();
	else if(str[0]=='-')
	  if((stringstream(str)>>i))
	    p.pushNum(i);
	  else
	    p.sub();
	else if(str[0]=='*')
	  p.mult();
	else if(str[0]=='/')
	  p.div();
	else if(str[0]=='~')
	  p.neg();
        }
    }
  if(p.total->empty())
	exit(-1);
  cout << "Result is: " << p.getTopValue() << endl;
  return 0;
}
 
