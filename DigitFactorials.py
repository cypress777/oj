# 9! = 362880
# 362880 * x < 10 ^ x => x = 7

from math import factorial

fac = [factorial(i) for i in range(0, 10)]
print(fac)

res = 0
for i in range(3, pow(10, 7)):
    sum = 0
    n = i
    while n > 0:
        sum += fac[n%10]
        n = n // 10
    if sum == i:
        res += i

print (res)