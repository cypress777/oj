import MathUtils
primeTab = [str(n) for n in MathUtils.genPrimeTab(1000000)]
primeFac = []

count = 0
num = 11

for n in primeTab:
    if count > 11:
        break

    if int(n) < 10:
        continue

    isTrunck = True
    num = str(n)
    for i in range(1, len(num)):
        if not (num[0:i] in primeTab) or not (num[i : :] in primeTab):
            isTrunck = False
            break

    if isTrunck:
        primeFac.append(n)
        count += 1
        print ("the {}th prime: {}".format(count, n))

print (primeFac)