def selections(n, r):
    if n < r:
        return 0
    if n == r:
        return 1
    x = min(r, n - r)
    xx = max(r, n - r)
    a = 1
    for i in range(1, x + 1):
        a *= i
    b = a
    for i in range(x + 1, xx + 1):
        b *= i
    c = b
    for i in range(xx + 1, n + 1):
        c *= i
    return c / (a * b)

count = 0
for n in range(1, 101):
    for r in range(0, n + 1):
        if selections(n, r) > 1000000:
            count += 1
print(count)
