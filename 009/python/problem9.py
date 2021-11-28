#! /bin/env python
import sys
max = 1000

for i in range(1,max):
  for j in range(i+1, max-i):
    if (i**2 + j**2 == (max-i-j)**2):
      print("Found: i =", i, "j =", j, "k =", max-i-j)
      print("Product = ",i*j*(max-i-j))
      sys.exit(0)
