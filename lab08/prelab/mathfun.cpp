#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int main() {
  int x;
  int y;
  cout << "Enter the first parameter: ";
  cin >> x;
  cout << "Enter the second parameter: ";
  cin >> y;
  cout << product(x,y) << "\n";
  cout << power(x,y) << "\n";
}