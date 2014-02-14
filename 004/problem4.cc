#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

  if (argc != 2) {
    cout << "Wrong number of arguments." << endl;
    return 1;
  }

  int max = 0;
  int digits = atoi(argv[1]);
  int x = pow(10, digits) -1;
  
  //cout << n1 << " " << n2 << endl;

  bool solution = false;
  for(int i = x; i <= x; ++i) {
    for(int j = x; j <= x; j++) { 
      int n = i * j;
      string s, t;
      stringstream repr;

      repr << n;
      s = repr.str();
      t = s;

      reverse(s.begin(), s.end());
      cout << t << " and " << s << endl;

      if (s.compare(t) == 0) {
        if (i*j > max) {
          max = i*j;
        }
      }
    }
  }
  cout << max << endl;

  return 0;
}
