import math

def P(n):
    return n * (3 * n - 1) / 2

def isPen(num):
    i = 1
    while i * (3 * i - 1) / 2.0 <= num:
        if i * (3 * i - 1) / 2.0 == num:
            return True
        i += 1
    return False

i = 1  # D = P(i)
m = 1
n = 2
while True:
    D = P(i)
    max_step = (D + 2) / 3.0


    while m < n and (i + n) < max_step:
        if D + P(i + m) < P(i + n):
            m += 1
        elif D + P(i + m) > P(i + n):
            n += 1
        else:
            print(D, P(i + m), P(i + n), m , n, max_step)
            break

    if isPen(P(i + m) + P(i + n)):
        print("result: ", D, P(i + m), P(i + n))
        break

    i += 1
    m = 1
    n = 2
