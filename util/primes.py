#! /bin/env python

import math

class Sieve:
  
  def __init__(self, size):
    self._sieve = [False] * (size)

  def flip(self, n):
    self._sieve[n-1] = not self._sieve[n-1]
  
  def reset(self, n):
    self._sieve[n-1] = False
  
  def isPrime(self, n):
    return self._sieve[n-1] 

class Primes:
  
  def __init__(self, limit):
    self.limit = limit
    self.roof = int(math.ceil(math.sqrt(limit)))
    self.primes = [2,3,5]
    self.sieve = Sieve(limit)

  def genPrimes(self):
    for i in range(1,self.roof):
      for j in range(1, self.roof):
        n = 4 * i**2 + j**2
        if ( n <= self.limit and (n % 12 == 1 or n % 12 == 5)):
          self.sieve.flip(n)
    
        n = 3 * i**2 + j**2
        if (n <= self.limit and ( n % 12 == 7)):
          self.sieve.flip(n)
    
        n = 3 * i**2 - j**2
        if ((i > j) and (n <= self.limit) and (n % 12 == 11)):
          self.sieve.flip(n)
    
    # Mark multiples
    for r in range(5, self.roof): 
      if self.sieve.isPrime(r):
        for i in range(r**2, self.limit, r**2):
          self.sieve.reset(i)
    
    for a in range(7, self.limit):
      if (self.sieve.isPrime(a)):
        self.primes.append(a)
    
  def getPrimes(self):
    return self.primes
 
  def getPrime(self, n):
    return self.primes[n-1]
