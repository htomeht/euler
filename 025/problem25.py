#! /bin/env python

import fibonacci

fib = fibonacci.Fibonacci()

done = False
while done != True:
  f = fib.next()
  if (len(str(f)) == 1000):
    done = True
    print f
    print fib.getTerm()
