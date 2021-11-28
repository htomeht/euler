#! /bin/env python

import math
import primes
from collections import Counter
from itertools import combinations

class Factorize:

  def __init__(self, limit):
    self.limit = limit
    self.factors = Counter([1])
    self.divisors = {1:1} 
    self.primes = primes.Primes(limit)

  def getFactors(self):
    return self.factors
    
  def getSize(self):
    return len(self.factors)

  def factorize(self, number):
    self.reset(number)

    for prime in self.primes.getPrimes():
      n = number
      divisor = 1
      while int(n % prime) == 0:
        self.factors[prime] += 1
        divisor *= prime
        if divisor != number:
          self.divisors[divisor] = divisor

        n = int(n/prime)
    return self

  def getDivisors(self):
    c = combinations(self.divisors, 2) 
    for x,y in c:
      divisor = x*y 
      if self.number % divisor == 0 and divisor < self.number:
        self.divisors[divisor] = divisor
    for d in self.divisors:
      divisor = d*d 
      if self.number % divisor == 0 and divisor < self.number:
        self.divisors[divisor] = divisor
    return self.divisors
  
  def reset(self, number):
    self.factors = Counter([1])
    self.divisors = {1:1} 
    self.number = number


  #def simple(self):
  #  i = 2
  #  while i < self.compound:
  #    if self.compound % i == 0:
  #      self.factors.append(i)
  #    i += 1
