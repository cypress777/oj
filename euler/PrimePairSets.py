import MathUtils as mu

pt = mu.genPrimeTab(100000)
ppt = mu.genPrimeTab(1000000)
lpt = len(pt)
sidx = []
ss = pt[-1] * 5

def get_digit(num):
    d = 0
    while num // 10 > 0:
        num //= 10
        d += 1
    return d + 1


def has_property(l):
    x = pt[l[-1]]
    dx = get_digit(x)
    for j in range(0, len(l) - 1):
        xx = pt[l[j]]
        dxx = get_digit(xx)
        a = x + xx * pow(10, dx)
        b = xx + x * pow(10, dxx)
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
        idxx = list(idx)
        idxx.append(ii)
        if sum([pt[k] for k in idxx]) + (5 - len(idxx)) * pt[ii] > ss:
            break
        if has_property(idxx):
            expand_list(idxx)

expand_list([])
print(lpt)
print(sidx)
print([pt[i] for i in sidx])
print(sum(pt[i] for i in sidx))