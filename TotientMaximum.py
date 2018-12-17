import MathUtils as mu

pt = mu.genPrimeTab(1000000)

def get_p(n):
    pl = set()
    i = 0
    while pt[i] < n:
        if n % pt[i] == 0:
            pl.add(pt[i])
            n = n // pt[i]
            i = 0
        else:
            i += 1
    if pt[i] == n:
        pl.add(pt[i])
    return pl

def phi(n):
    res = []
    for i in range(1, n):
        b = True
        for j in get_p(n):
            if i % j == 0:
                b = False
                break
        if b:
            res.append(i)
    return res

max = 1
n = 1
for i in range(2, 50):
    p = phi(i)
    if i / len(p) > n / max:
        max = len(p)
        n = i
    print(i, p)
print(n, max, n / max)