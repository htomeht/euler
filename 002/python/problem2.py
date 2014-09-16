#! /bin/env python

def fib(upto):
  n1, n2 = 0, 1

  while n2 < upto:
    n1, n2 = n2, n1+n2
    yield n1

print sum([x for x in fib(4000000) if (x % 2 == 0)])

