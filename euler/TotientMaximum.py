import MathUtils as mu

pt = mu.genPrimeTab(1000003)

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
        # res -= (res / pp)
        res = res // pp * (pp - 1)
    return res

max = 1
n = 1
for i in range(2, 1000001):
    p = phi(i)
    if float(i) / p > float(n) / max:
        max = p
        n = i
    # print(i, p)
print(n, max, float(n) / max)