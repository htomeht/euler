#! /bin/env python

import math

class Factorize:

  def __init__(self, compound):
    self.compound = compound
    self.roof = int(math.ceil(math.sqrt(compound)))
    self.factors = []

  def getFactors(self):
    return self.factors
    
  def getSize(self):
    return len(self.factors)

  def factorize(self):
    i = 2
    while i <= self.roof:
      if (self.compound % i == 0):
        self.factors.append(i)
        self.compound = self.compound/i
      else: 
        i += 1
    
