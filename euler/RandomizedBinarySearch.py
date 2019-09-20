def B(n):
    x = 1;
    while 2**x - 1 < n:
        x+=1

    last = n - (2**(x - 1) - 1)

    res = 0;
    for i in range(1, x):
        res += i * (2**(i - 1)) / n
    res += last * x / n

    return res

def R(n):
    res = 1
    for i in range(2, n + 1):
        ii = i * i
        res = (ii - 1) / ii * res - (ii - 2 * i + 1) / ii + 1

    return res

MM = int(1e10)
b = B(MM)
print(b)
r = R(MM)
print(b, r, r - b)