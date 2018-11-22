import MathUtils as mu

pt = mu.genPrimeTab(10000)
ppt = mu.genPrimeTab(1000000)
lpt = len(pt)
sidx = []
pl = []
ss = pt[-1] * 5

def get_digit(num):
    d = 0
    while num // 10 > 0:
        num //= 10
        d += 1
    return d


def has_property(l):
    for i in range(0, len(l) - 1):
        x = pt[l[i]]
        dx = get_digit(x)
        for j in range(i + 1, len(l)):
            xx = pt[l[j]]
            dxx = get_digit(xx)
            a = x + xx * pow(10, dx + 1)
            b = xx + x * pow(10, dxx + 1)
            if not mu.isPrimeAug(a, ppt) or not mu.isPrimeAug(b, ppt):
                return False
    return True

def expand_list(idx):
    global ss
    global sidx

    if len(idx) > 4:
        s = sum([pt[i] for i in idx])
        if s < ss:
            ss = s
            sidx = idx

    i = -1
    if len(idx) > 0:
        if idx[-1] >= lpt - 1:
            return
        i = idx[-1]

    for ii in range(i + 1, lpt):
        idxx = idx.copy()
        idxx.append(ii)
        if sum([pt[k] for k in idxx]) + (5 - len(idxx)) * pt[ii] > ss:
            break
        if has_property(idxx):
            expand_list(idxx)

expand_list([])
print(sidx)
print(sum(sidx))