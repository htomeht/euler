#include <iostream>
#include <map>

using namespace std;

int main() {
  unsigned long max = 1000000;
  unsigned long maxstart = 0;
  unsigned long maxlength = 0;
  unsigned long i = 2;

  for(i; i < max; ++i) {
    unsigned long inner = i;
    int length = 0;

    while (inner != 1) {
      ++length;
      if (inner%2 == 0) {
        inner = inner/2;
      }
      else {
        inner = 3*inner +1;
      }
    }

    if (length > maxlength) {
      maxlength = length;
      maxstart = i;
    }

  }
  cout << "Max: " << maxstart << endl;
}
