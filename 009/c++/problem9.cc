#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int max = 1000;
  for (int i = 1; i < max; i++) {
    for (int j = i+1; j < max -i; j++) {
      int k = max - i - j;

      //cout << "Numbers : " << i << " " << j << " " << k << endl;
      if (pow(i, 2) + pow(j, 2) == pow(k, 2)) {
        cout << "Product = " << i*j*k << endl;
      }
    }
  }
}
