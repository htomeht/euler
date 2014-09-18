#! /bin/env python

import math

class Primes:
  
  def __init__(self, limit):
    self.limit = limit
    self.roof = int(math.ceil(math.sqrt(limit)))
    self.primes = [2,3,5]
    self.sieve = [0]*limit

  def genPrimes(self):
    for i in range(1,self.roof):
      for j in range(1, self.roof):
        n = 4 * i**2 + j**2
        if ( n <= self.limit and (n % 12 == 1 or n % 12 == 5)):
          self.sieve[n] = 1
    
        n = 3 * i**2 + j**2
        if (n <= self.limit and n % 12 == 7):
          self.sieve[n] = 1
    
        n = 3 * i**2 - j**2
        if ( i > j and n <= self.limit and n % 12 == 11):
          self.sieve[n] = 1
    
    # Mark multiples
    for r in range(5, self.roof): 
      if self.sieve[r] == 1:
        for i in range(r**2, self.limit, r**2):
          self.sieve[i] = 0
    
    for a in range(7, self.limit):
      if (self.sieve[a] == 1):
        self.primes.append(a)
    
    return self.primes
