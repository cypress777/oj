import math

def d(n):
    res = 1
    for i in range(2, math.ceil(math.sqrt(n-1))):
        if (n%i == 0):
            res += i
            res += n//i
    return res

res = 0
flags = [0]*9999
flags[0] = 1

for i in range(2, 10000):
    if flags[i-1] == 1:
        continue
    else:
        amc = d(i)
        if amc == i:
            continue
        aamc = d(amc)
        if aamc == i:
            print("i/d(i)/d(amc): {}/{}".format(i, amc))
            res += i
            flags[i-1] = 1
            if amc < 10000 and flags[amc - 1] != 1:
                res += amc
                flags[amc-1] = 1
print(res)
