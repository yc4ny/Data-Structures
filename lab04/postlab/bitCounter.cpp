#include <iostream>
using namespace std;
int numOfOnes(int n);
int main(int argc, char **argv)
{
  if(argc!=2){
    cout<<" You need to enter one parameter!"<<endl;
    exit(1);
  }
  int num = atof(argv[1]);
  cout<<numOfOnes(num)<<endl;
}

// recursive function that returns the number of 1's in the binary representation of n
int numOfOnes(int n)
{
  if(n==0){
    return 0;
  }
  else if(n==1){
    return 1;
  }
  else
    return numOfOnes(n/2)+numOfOnes(n%2);
}
