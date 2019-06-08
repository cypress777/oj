def showed(bmod, cmod, bs, cs):
    for i in range(len(bs)):
        if bs[i] == bmod and cs[i] == cmod:
            return True
    return False

res = 0
for a in range(3, 1001):
    aa = a * a
    b = a - 1
    c = (a + 1) % aa
    bs = []
    cs = []

    cur = 0
    while not showed(b, c, bs, cs):
        bs.append(b)
        cs.append(c)
        cur = max((b + c) % aa, cur)
        b = b * (a - 1) % aa
        c = c * (a + 1) % aa
    res += cur

print(res)