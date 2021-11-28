#! /bin/env python

from functools import reduce
from operator import mul

f = open("numbers")
number = f.read()
f.close()

def maxsum(l):
  mx = 0
  for i in range(len(l)-1):
    mx = max(mx, reduce(mul, [int(x) for x in l[i:i+13]]))
  return mx

sections = [x for x in number.split("0") if len(x) >= 13]
mx = max([maxsum(x) for x in sections])

print(mx)
