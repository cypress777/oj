import MathUtils as mu

pt = mu.genPrimeTab(1000001)

sum = 0
for k in range(2, 1000001):
    sum += mu.phi(k, pt)
print(sum)