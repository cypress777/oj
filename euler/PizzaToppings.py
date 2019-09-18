import math
import numpy as np

MM = 1e15

def get_factorials(n):
    k = 1
    for i in range(1, n + 1):
        k *= i
    return k

def get_factors(n):
    res = []
    for i in range(1, n):
        if n % i == 0:
            res.append(i)
    return res

def filter_permutation(m, n):
    return get_factorials(m * n) / math.pow(get_factorials(n), m)

tot = 0
for m in range(2, 100):
    t = [0]

    n = 1
    for n in range(1, 100):
        tcnt = filter_permutation(m, n)

        factors = get_factors(n)
        for v in factors:
            tcnt -= (t[v] * m * v)
        tcnt /= (m * n)

        cnt = tcnt
        for v in factors:
            cnt += t[v]

        if cnt > MM:
            break

        t.append(tcnt)
        tot += cnt

    if n == 1:
        break

print(int(tot))
