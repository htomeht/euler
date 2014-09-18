#! /bin/env python
import primes

p = primes.Primes(1000000)
p.genPrimes()

l = p.getPrimes()


print("Length is: ", len(l))
print("Prime is: ", l[10000])
