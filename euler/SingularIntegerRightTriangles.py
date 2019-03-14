import MathUtils as mu
import math

L = 1500000
llist = []
llistc = [0] * (L + 1)
for i in range(L + 1):
    llist.append(set())

print(len(llist), len(llist[0]))

cntc = 0
max_range = int(math.sqrt(L / 2))
for m in range(1, max_range):
    for n in range(1, m):
        if (m + n) % 2 == 0:
            continue
        if mu.gcd(m, n) > 1:
            continue
        mm = m * m
        nn = n * n
        a = mm - nn
        b = 2 * m * n
        c = mm + nn
        length = a + b + c
        k = 1
        while k * length <= L:
            llist[k * length].add(k * c)
            llistc[k * length] += 1
            if llistc[k * length] == 1:
                cntc += 1
            if llistc[k * length] == 2:
                cntc -= 1
            k += 1

cnt = 0
for i in range(len(llist)):
    if i == 120:
        print(llist[i], len(llist[i]))
    if len(llist[i]) == 1:
        cnt += 1
print(cnt, cntc)