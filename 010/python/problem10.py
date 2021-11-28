import primes

p = primes.Primes(2000000)
p.genPrimes()
print("Sum of Primes",sum(p.getPrimes()))
