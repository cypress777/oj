import MathUtils as mu
prime_tab = mu.genPrimeTab(1000000)

k = 0
s = 2

pn = 0.0
total = 1.0
ratio = 100
while ratio > 0.1:
    len = 2 * k + 1
    peri = 4 * len + 4
    p = [s + len, s + len + len + 1, s + len + 2 * (len + 1), s + len + 3 * (len + 1)]
    total += 4
    for pp in p:
        if mu.isPrimeAug(pp, prime_tab):
            pn += 1.0
    ratio = pn / total
    k += 1
    s += peri

print(2 * (k - 1) + 3)