#! /bin/env python

digits = 3
max_number = 10**3 -1
solution = False

for i in range(max_number, 1, -1):
  if (solution):
    print "Solution found: ", n
    print "Numbers: ", i, j
    break
  for j in range(max_number, 1, -1):
    n = i * j
    sn = str(n)

    if (sn[:len(sn)/2] == sn[(len(sn)/2)+1:]):
      solution = True
      break

