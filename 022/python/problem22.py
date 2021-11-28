#! /bin/env python
namelist = open("names.txt")
names = namelist.read()
namelist.close()
names = names.replace("\"","").split(",")
names.sort()

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def strValue(s):
  print(s) 
  return sum([alpha.index(x) + 1 for x in s])

total = 0
for i in range(1,len(names)+1):
  total += i*strValue(names[i-1])

print(total)  
