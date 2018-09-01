pairs = set()

for i in range(1, 10):
    for m in range(1, 10):
        for n in range(1, 10):
            if m == n:
                continue
            if (m*10 + i) % m == 0 and (n + i*10) % n == 0 and (m*10 + i) / m == (n + i*10) / n and (m*10 + i) < (n + i*10):
                pairs.add((m*10 + i, n + i*10))
            if (i*10 + n) % (m*10 + i) == 0 and n % m == 0 and (i*10 + n) / (m*10 + i) == n / m:
                pairs.add((m*10 + i, i*10 + n))

print(len(pairs))
for iter in pairs:
    print("{}/{}".format(iter[0], iter[1]))