#include <iostream>

#include "../util/Primes.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2)
    return 1;

  unsigned long prime = atol(argv[1]);
  utl::Primes primes = utl::Primes();

  primes.generatePrimes();
  
  cout << primes.getPrime(prime) << endl;

  return 0;

}
