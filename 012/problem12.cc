#include <iostream>
#include <iterator>
#include <cstdlib>

#include "factorize.h"

using namespace std;

int count_factors(map<long, int> fmap) {
  
  map<long,int>::iterator iter;

  int sum = 1;
  for(iter = fmap.begin(); iter != fmap.end(); ++iter) {
  //  cout << sum << endl;
    cout << "Factor : " << iter->first << "; Power : " <<  iter->second << endl;
    sum *= (iter->second) + 1;
  }

  //cout << sum << endl;
  
  return sum;
}

int main(int argc, char* argv[]) {

  if (argc != 3) {
    cout << "Wrong number of arguments!" << endl;
    return -1;
  }
  int minfactors = atoi(argv[1]);

  unsigned long n = atol(argv[2]);
  unsigned long triangle;

  bool done = false;
  while(!done) {
    triangle = n*(n+1)/2;
    utl::Factorization f = utl::Factorization(triangle);
    int factors = count_factors(f.get_map());

    cout << "Counting: "  << triangle << 
            " has factors: " << factors << endl;
    if (factors > minfactors) done = true;
    else ++n;
  }
  cout << "Result: " << triangle << " n = " << n <<  endl;
}
