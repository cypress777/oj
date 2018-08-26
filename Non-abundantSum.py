import math
import MathUtils

flags = [-1]*(28124)

def isAbundant(n):
    if MathUtils.d(n) > n:
        return True
    return False

def isAbundantSum(n):
    for i in range(1, math.floor(n/2)+1):
        is_part0_ab = flags[i] if flags[i] != -1 else isAbundant(i)
        if flags[i] == -1:
            flags[i] = is_part0_ab

        is_part1_ab = flags[n - i] if flags[n - i] != -1 else isAbundant(n - i)
        if flags[n - i] == -1:
            flags[n - i] = is_part1_ab

        if is_part0_ab and is_part1_ab:
            return i
    return 0

def run():
    res = 0
    for num in range(1, 28123):
        ab = isAbundantSum(num)
        if ab == 0:
            res += num
    print(res)

run()