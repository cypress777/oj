import MathUtils

res = 0
flags = [0]*9999
flags[0] = 1

for i in range(2, 10000):
    if flags[i-1] == 1:
        continue
    else:
        amc = MathUtils.d(i)
        if amc == i:
            continue
        aamc = MathUtils.d(amc)
        if aamc == i:
            print("i/d(i)/d(amc): {}/{}".format(i, amc))
            res += i
            flags[i-1] = 1
            if amc < 10000 and flags[amc - 1] != 1:
                res += amc
                flags[amc-1] = 1
print(res)
