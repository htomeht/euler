#! /bin/env python

from factorize import Factorize

compound = 6008

factors = Factorize(compound)
factors.factorize()


print ("Max = ", str(compound))
print ("Biggest factor = ", str(factors.getFactors()[-1]))
print ("List = ", factors.getFactors())
