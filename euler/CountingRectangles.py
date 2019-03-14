import math

def calc(m, n):
    return (m + 1) * m * (n + 1) * n / 4

MM = 2000000
min_diff = MM
min_m = 0
min_n = 0
min_res = 0
for m in range(1, 2000):
    for n in range(m, 2000):
        res = calc(m, n)
        diff = math.fabs(MM - res)
        if diff < min_diff:
            min_diff = diff
            min_res = res
            min_m = m
            min_n = n
print(min_res, min_diff, min_m, min_n, min_m * min_n)