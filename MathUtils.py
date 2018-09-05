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

def isPrime(N):
    if N < 1:
        return False
    if N == 1 or N == 4 or N ==6:
        return False
    if N == 2 or N == 3 or N == 5 or N == 7:
        return True
    for i in range(2, N):
        if N != i and N%i == 0:
            return False
    return True

def genPrimeTab(N):
    count = 0
    primeTab = []
    isPrime = []
    for n in range(0, N+1):
        isPrime.append(0)
    for i in range(2, N):
        if isPrime[i] == 0:
            primeTab.append(i)
            count += 1

        for j in range(0, count):
            if i * primeTab[j] > N:
                break
            isPrime[i * primeTab[j]] = 1
            if i % primeTab[j] == 0:
                break

    primeTab = primeTab[0 : count]
    return primeTab

if __name__ == '__main__':
    tab = genPrimeTab(10)
    print (tab)
