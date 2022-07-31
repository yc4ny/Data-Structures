#include <iostream>
#include "timer.h"

extern "C" int threexplusone(int x);

int main() {
  int x;
  int n;
  std::cout << "Please enter the integer to evaluate: ";
  std::cin >> x;
  std::cout << "Please enter the number of times to evaluate: ";
  std::cin >> n;
  int result = threexplusone(x);
  std::cout << "Number of operations required to reach 1: " << result << "\n";

  timer t;
  t.start();
  for(int i = 0; i < n; i++) {
    threexplusone(x);
  }
  t.stop();
  double timeElapsed = t.getTime() * 1000;
    std::cout << "Total time it took(in milliseconds) to run " << n << " times: " <<
      timeElapsed;
  return 0;
}
  