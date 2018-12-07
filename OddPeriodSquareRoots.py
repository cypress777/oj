import math

def get_next(b, c, d, n):
    bi = b * d
    ci = -1 * c * d
    di = b * b - c * c
    return a, b, c, d

def sq_list(n, l):
    if len(l) == 0:
        a0 = int(math.sqrt(n))
        d0 = n - a0 * a0
        a1 = 2 * a0 // d0
        b0 = 1
        c0 = a0 % d0 * 2 - a0
        l.append([a1, b0, c0, d0])
    else:
        ai = l[-1][0]
        aii, bi, ci, di = get_next(l[-1][1], l[-1][2], l[-1][3], n)
        if len(l) > 1 and ai == l[0][0] and bi == l[1][1] and ci == l[1][2] and di == l[1][3]:
            return l
        else:
            l.append([aii, bi, ci, di])
            sq_list(n, l)