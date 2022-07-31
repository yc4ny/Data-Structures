#include <iostream>
using namespace std;

// function that computes x^n recursively
int xton(int x,int n)
{
  if(n==0)
    return 1;
  else
    return x*xton(x,n-1);
}

// takes in exactly 2 inputs and raises the first one to the second one 
// and outputs the result
int main()
{
  int x,y,z;
  cout << "Enter two integer values" <<endl;
  cin >> x;
  cin >> y;
  z = xton(x,y);
  cout << z << endl;
  return 0;
}
