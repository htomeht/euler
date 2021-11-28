#! /bin/env python

# Solve Problem 23 for Project Euler
# 

from factorize import Factorize
from itertools import combinations

lower_limit = 12 
higher_limit = 500
#higher_limit = 28123

deficient = []
perfect = []
abundent = []
rest = []
result = dict([(x,x) for x in range(1,higher_limit+1)])

def gen_factors(): 
  factorial = Factorize(higher_limit)

  for n in range(lower_limit, higher_limit+1):
    factorial.factorize(n)
    divisor_sum = sum(factorial.getDivisors())

    if divisor_sum < n: deficient.append(n)
    elif divisor_sum == n: perfect.append(n)
    else: abundent.append(n)

def gen_result():
  c = combinations(abundent, 2)

  for x,y in c:
    result.pop(x+y, None)

  for a in abundent:
    result.pop(a+a, None)

def main():
  gen_factors()
  gen_result()

if __name__ == "__main__":
  main()
  #print("Deficient:",deficient)
  #print("Perfect:",perfect)
  print("Abundent:",abundent)
  print("Result:",result)
  print("Sum:",sum(result))
