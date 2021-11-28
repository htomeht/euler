#include <iostream>
#include <numeric>
#include <vector>
#include "../util/Primes.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2)
    return 1;

  unsigned long max = atol(argv[1]);

  utl::Primes primes = utl::Primes();

  vector<unsigned long> vprimes = primes.generatePrimes();
  unsigned long res = accumulate(vprimes.begin(), vprimes.begin()+max, 0);
  //for (int i = 0; i < vprimes.size(); i++)
  //  cout << " " << vprimes[i];
  //cout << endl;
  cout << res << endl;
  
  return 0;
  
}
