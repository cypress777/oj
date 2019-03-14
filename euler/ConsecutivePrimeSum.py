import MathUtils as mu

N = 1000000

prime_tab = mu.genPrimeTab(N)
reversed_tab = prime_tab[:]
reversed_tab.reverse()

def sum_length(prime):
    start = 0
    end = 0
    sum = 0
    while sum < prime:
        if prime_tab[end] < prime - sum:
            sum += prime_tab[end]
            end += 1
        elif prime_tab[end] > prime - sum:
            sum -= prime_tab[start]
            start += 1
        elif prime_tab[end] == prime - sum:
            return end - start + 1

max = 1
num = 2
for prime in reversed_tab:
    if prime < N / 10:
        break
    length = sum_length(prime)
    if length > max:
        max = length
        num = prime
print(max)
print(num)