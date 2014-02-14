/*
 * Generate a list (vector) of primes.
 *
 */

#include<vector>
#include <iostream>
#include <cmath>
#include <boost/dynamic_bitset.hpp>

namespace utl {

class Primes {

public:
  Primes() 
  : _max(1000000), _root(ceil(sqrt(_max))) { }

  std::vector<unsigned long> generatePrimes(unsigned long n);
  std::vector<unsigned long> getPrimes() { return _primes; }
  unsigned long getPrime(unsigned long n) { return _primes[n-1]; }

private:
  const unsigned long _max;
  const unsigned long _root;
  
  std::vector<unsigned long> _primes; 

};

std::vector<unsigned long> Primes::generatePrimes(unsigned long limit) {
  // 1. Fill results
  _primes.push_back(2); 
  _primes.push_back(3);
  _primes.push_back(5);

  // 2. Create a sieve init 0
  boost::dynamic_bitset<> sieve(_max);

  unsigned long i, j, n;

  // 3. 
  for(i = 1; i <= _root; ++i) {
    for (j = 1; j <= _root; ++j) {
      // N <- 4x**2 + y**2
      n = 4*pow(i, 2) + pow(j,2);
      if (n <= _max && ( n % 12 == 1 || n % 12 == 5)) 
        sieve.flip(n);

      // N <- 3x**2 + y**2
      n = 3*pow(i, 2) + pow(j,2);
      if (n <= _max && n % 12 == 7)
        sieve.flip(n);

      // N <- 3x**2 - y**2
      n = 3*pow(i, 2) - pow(j,2);
      if (i > j && n <= _max && n % 12 == 11)
        sieve.flip(n);
      }
    }

    // Mark all multiples
    for (unsigned long r = 5; r <= _root; ++r) {
      if(sieve[r]) {
        //std::cout << r << std::endl;
        for (i = pow(r,2); i < _max; i+= pow(r,2)) {
          sieve.reset(i);
        }
      }
    }
    // Add primes
    for (unsigned long a = 7; a < limit; a++) {
      if (sieve[a]) {
        _primes.push_back(a);
      }
    }
  return _primes;
  }
}
