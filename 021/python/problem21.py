#! /bin/env

from factorize import Factorize

def amicable(n):
  f1 = Factorize(n)
  f1.simple()

  s1 = sum(f1.getFactors())

  f2 = Factorize(s1)
  f2.simple()

  s2 = sum(f2.getFactors())

  return s1,s2

an = [] # Amicable numbers
for n in range(1,10000):
  s1, s2 = amicable(n)
  if n == s2 and s1 != s2:
    if s1 not in an: an.append(s1)
    if s2 not in an: an.append(s2)

print("Numbers: ", an)
print("Sum: ", sum(an))
