import primes

limit = 20
p = primes.Primes(limit)


answer = 1
for prime in p.genPrimes():
  power = prime
  while power * prime < limit:
    power = power * prime 
  answer *= power

print answer


   
