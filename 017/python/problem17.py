#! /bin/env python
upto20 = {0:"",1:"one", 2:"two",3:"three",4:"four",5:"five",6:"six",7:"seven",8:"eight",9:"nine",
          10:"ten",11:"eleven",12:"twelve",13:"thirteen",14:"fourteen",15:"fifteen",16:"sixteen",
          17:"seventeen",18:"eighteen",19:"nineteen"}
tens = {0:"",2:"twenty", 3:"thirty",4:"forty",5:"fifty",6:"sixty",7:"seventy",8:"eighty",9:"ninety"}

def ands(n):
  if n == 0: return ""
  else: return "and"


def translate(n):
  if n < 20: return upto20[n]
  if n < 100: return  (tens[int(str(n)[0])] + translate(int(str(n)[1:]))) 
  if n < 1000: return upto20[int(str(n)[0])] + "hundred" + ands(int(str(n)[1:])) + translate(int(str(n)[1:]))
  if n == 1000: return "onethousand"


l = [translate(x) for x in range(1001)]

for x in range(1001):
  print("Element: " + str(x) + " :: " + l[x]+ " :: " + str(len(l[x]))) 

print(len("".join(l)))
