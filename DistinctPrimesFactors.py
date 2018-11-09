import math
import MathUtils


prime_tab = MathUtils.genPrimeTab(1000000)
print(len(prime_tab))

def GetFactors(num):
    factors = set([])
    if num < 2:
        return factors

    while (not num in prime_tab):
        for factor in prime_tab:
            if factor > num:
                break
            remain = num * 1.0 / factor
            if int(remain) == remain:
                factors.add(factor)
                num = remain
                break
    if num > 1:
        factors.add(num)
    return factors

def Result():
    num = 2
    consecutive_count = 0
    while (consecutive_count < 4):
        factors = GetFactors(num)
        if len(factors) == 4:
            consecutive_count += 1
        else:
            consecutive_count = 0
        num += 1
        if num > 999999:
            break
    print('result: ', num)

Result()