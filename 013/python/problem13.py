#! /bin/env python

file = open("numbers")
_sum = 0

for n in file:
  _sum += int(n)

print _sum / 1000
