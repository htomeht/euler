#! /bin/env python

import factorize

compound = 600851475143

factors = factorize.Factorize(compound)
factors.factorize()


print "Max = ", str(compound)
print "Biggest factor = ", str(factors.getFactors()[-1])
print "List = ", factors.getFactors() 
