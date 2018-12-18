import MathUtils as mu

pt = mu.genPrimeTab(10000001)

def get_p(n):
    pl = []
    for p in pt:
        if p * p > n:
            break
        while n % p == 0:
            pl.append(p)
            n //= p
    if n > 1:
        pl.append(n)
    return pl

def phi(n):
    res = n
    p = set(get_p(n))
    for pp in p:
        res = res // pp * (pp - 1)
    return res

min = 1
minn = 1000
for n in range(2, 10000001):
    p = phi(n)
    pp = p
    nn = n
    pl = []
    nl = []
    while p > 0:
        pl.append(p % 10)
        p //= 10
    while n > 0:
        nl.append(n % 10)
        n //= 10
    pl.sort()
    nl.sort()
    if (pl == nl) and float(nn) / pp < float(minn) / min:
        minn = nn
        min = pp
print(minn, min, float(minn) / min)
print(minn, min, float(minn) / min)