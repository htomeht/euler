r = range(1, 101)
print sum(r)**2 - sum(map(lambda x: x*x, r))
