import MathUtils as mu
import math

pt = mu.genPrimeTab(12000)

sum = 0
for d in range(2, 12001):
    nmin = math.ceil((d + 1) / 3)
    nmax = math.floor((d - 1) / 2)
    # print(d, nmin, nmax)
    for n in range(nmin, nmax + 1):
        if mu.gcd(n, d) == 1:
            sum += 1
print(sum)