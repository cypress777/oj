import math

# Sum of the proper divisors of n
def d(n):
    res = 1
    i = 2
    while i < math.ceil(math.sqrt(n)):
        if (n%i == 0):
            res += i
            res += n//i
        i += 1
    if i*i == n:
        res += i
    return res