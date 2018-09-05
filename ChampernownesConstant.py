def d(num):
    n = 0
    sum = 0
    while sum < num:
        n += 1
        sum = 9 * pow(10, n - 1) * n

    offset = num - 1
    for k in range(1, n):
        offset -= 9 * pow(10, k - 1) * k

    idx = pow(10, n - 1) + offset/n
    idxx = offset%n

    digit = int(str(idx)[idxx])
    return(digit)

print(d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000))