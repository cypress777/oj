import math
import time

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

def isPrime(N):
    if N < 1:
        return False
    if N == 0 or N == 1 or N == 4 or N ==6:
        return False
    if N == 2 or N == 3 or N == 5 or N == 7:
        return True
    for i in range(2, N):
        if N != i and N%i == 0:
            return False
    return True

def isPrimeAug(n, pl):
    for p in pl:
        if n % p == 0:
            return False
        if p * p > n:
            return True

def genPrimeTab(N):
    count = 0
    primeTab = []
    isPrime = [0] * (N + 1)

    for i in range(2, N):
        if isPrime[i] == 0:
            primeTab.append(i)
            count += 1
        for prime in primeTab:
            if i * prime > N:
                break
            isPrime[i * prime] = 1
            if i % prime == 0:
                break
    return primeTab

def gcd(a, b):
    t = 1
    m = max(a, b)
    n = min(a, b)
    while t != 0:
        t = m % n
        m = n
        n = t
    return m

def get_prime_factors(n, pt):
    pl = []
    for p in pt:
        if p * p > n:
            break
        while n % p == 0:
            pl.append(p)
            n //= p
    if n > 1:
        pl.append(n)
    return pl

if __name__ == '__main__':
    time0 = time.time()
    tab = genPrimeTab(10)
    time1 = time.time()
    tab = genPrimeTab(100)
    time2 = time.time()
    tab = genPrimeTab(1000)
    time3 = time.time()
    tab = genPrimeTab(10000)
    time4 = time.time()
    tab = genPrimeTab(100000)
    time5 = time.time()

    print(time1 - time0)
    print(time2 - time1)
    print(time3 - time2)
    print(time4 - time3)
    print(time5 - time4)
