#include <iostream>

using namespace std;

int main() {

  

  int min = 0;
  int max = 1000;
  int sum = 0;

  for (int i = min; i < max; i++) {
    if ((i % 3 == 0 || i % 5 == 0))
      sum += i;
  }
  cout << sum << endl;

  
}
