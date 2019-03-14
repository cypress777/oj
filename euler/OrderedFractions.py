import MathUtils as mu
import math

pt = mu.genPrimeTab(1000001)

mn = 2
md = 5
for d in range(5, 1000001):
    n = int((3 * d - 1) / 7)
    if d // n == 0:
        n -= 1
    if mn * d < md * n:
        mn = n
        md = d
print(mn, md)