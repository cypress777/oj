from decimal import *
from math import sqrt

getcontext().prec = 102

def calc(n):
    s = str(Decimal(n).sqrt()).replace('.', '')
    # print(s)

    start = 0
    end = 100
    while int(s[start]) == 0:
        start += 1
        end += 1

    val = 0
    for i in range(start, end):
        val += int(s[i])
    return val

print(calc(2))

all_sum = 0
for n in range(100):
    nn = sqrt(n)
    if nn * nn != n:
        all_sum += calc(n)
print(all_sum)

