import MathUtils as mu

power = 6

prime_tab = mu.genPrimeTab(pow(10, power))
min_index = 0
min_prime = pow(10, power - 1)
while prime_tab[min_index] < min_prime:
    min_index += 1
prime_tab = prime_tab[min_index :]

for prime in prime_tab:
    index = [1, 2, 3]
    end = [3, 4, 5]
    prime_digits = [int(dig) for dig in reversed(str(prime))]
    while index[2] < end[2] or index[1] < end[1] or index[0] < end[0]:
        if prime_digits[index[0]] == prime_digits[index[1]] and prime_digits[index[0]] == prime_digits[index[2]]:
            family = set()
            for digit in range(0, 10):
                num = 0
                for k in range(0, power):
                    if k in index:
                        num += digit * pow(10, k)
                    else:
                        num += prime_digits[k] * pow(10, k)
                if num in prime_tab:
                    family.add(num)
            if len(family) > 7:
                print('result: ', family)
                exit()
        for i in [2, 1, 0]:
            if index[i] < end[i]:
                index[i] += 1
                if i < 2:
                    for j in range(i, 2):
                        index[j] = index[i] + j - i
                break

