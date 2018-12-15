import math

def gcd2(a, b):
    t = 1
    m = max(a, b)
    n = min(a, b)
    while t != 0:
        t = m % n
        m = n
        n = t
    return m

def gcd3(a, b, c):
    g = gcd2(abs(a), abs(b))
    g = gcd2(abs(g), abs(c))
    return a // g, b // g, c // g

def cal(b, c, d, n):
    nn = int(math.sqrt(n))
    bb = b * d
    cc = -1 * c * d
    dd = b * b * n - c * c
    aii = (bb * nn + cc) // dd
    cc = cc - aii * dd
    bi, ci, di = gcd3(bb, cc, dd)
    return aii, bi, ci, di

def sq_list(n, l):
    if math.sqrt(n) == int(math.sqrt(n)):
        return
        
    if len(l) == 0:
        a0 = int(math.sqrt(n))
        a1, b0, c0, d0 = cal(1, -1 * a0, 1, n)
        l.append([a1, b0, c0, d0])
        sq_list(n, l)
    else:
        ai = l[-1][0]
        aii, bi, ci, di = cal(l[-1][1], l[-1][2], l[-1][3], n)
        if len(l) > 1 and ai == l[0][0] and bi == l[1][1] and ci == l[1][2] and di == l[1][3]:
            # print([ll[0] for ll in l[:-1]])
            return 
        else:
            l.append([aii, bi, ci, di])
            sq_list(n, l)

count = 0
for k in range(2, 10000):
    l = []
    sq_list(k, l)
    ll = [ll[0] for ll in l[:-1]]
    if len(ll) % 2 == 1:
        count += 1
print(count)