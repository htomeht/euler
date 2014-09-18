#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

  if (argc != 2) 
    return 1;

  long max = atol(argv[1]);
  long answer = 1;

  for (long i = 2; i <= max; ++i) {
    if (answer % i != 0) {
      
      long power = i;

      while (power*i < max) {
          power = power*i;
      }
      
      answer = answer*power;

    }
  }
  cout << "The answer is " << answer << endl;
}
