import MathUtils

def f(n, a, b):
    res = n * n + a * n + b
    return res

PrimeNums = {0 : 0, 1 : 0, 2 : 0, 3 : 0, 4 : 1}

max_len = 0
max_a = -999
max_b = 0
max_product = 0
b = 0
while b < 1001:
    a = -999

    while a < 1001:
        a += 1

        n = 0
        len = 0
        quad = f(n, a, b)
        while (PrimeNums.has_key(quad) and PrimeNums[quad] == 1) or MathUtils.isPrime(quad):
            if not PrimeNums.has_key(quad):
                PrimeNums[quad] = 1
            n += 1
            len += 1
            quad = f(n, a, b)
        if not PrimeNums.has_key(quad):
            PrimeNums[quad] = 0
        if len > max_len:
            max_len = len
            max_a = a
            max_b = b
            max_product = a * b

    b += 1

print("max product {}, a {}, b {}, len {}".format(max_product, max_a, max_b, max_len))