import MathUtils as mu

prime_tab = mu.genPrimeTab(1000000)
lp = len(prime_tab)
print(lp)

def get_digit(num):
    d = 0
    while num // 10 > 0:
        num //= 10
        d += 1
    return d


def has_property(l):
    for i in range(0, len(l) - 1):
        x = l[i]
        dx = get_digit(x)
        for j in range(i + 1, len(l)):
            xx = l[j]
            dxx = get_digit(xx)
            if not mu.isPrimeAug(x + xx * pow(10, dx + 1), prime_tab) or not mu.isPrimeAug(xx + x * pow(10, dxx + 1),
                                                                                           prime_tab):
                return False
    return True


idx = [0, 1, 2, 3, 4, 5]
end = [lp - 5, lp - 4, lp - 3, lp - 2, lp - 1]

fin = False
while not fin:
    pl = [prime_tab[idx[n]] for n in range(0, 5)]
    if has_property(pl):
        print(pl)
        sum = 0
        for p in pl:
            sum += p
        print(sum)
        break

    mini = -1
    minp = prime_tab[-1]
    for i in range(0, 5):
        ii = 4 - i
        if idx[ii] == lp or (ii < 4 and not idx[ii] < idx[ii + 1] - 1):
            continue
        sub = prime_tab[idx[ii] + 1] - prime_tab[idx[ii]]
        if sub < minp:
            mini = ii
            minp = sub
    idx[mini] += 1
