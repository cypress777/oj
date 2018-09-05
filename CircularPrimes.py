import time
import MathUtils
import LexicographicPermutations as permutation

time0 = time.time()
primeTable = MathUtils.genPrimeTab(1000000)
time1 = time.time()
res = set()

time2 = time.time()
for i in range(len(primeTable)):
    prime = primeTable[i]

    k = 0
    while pow(10, k) < prime:
        k += 1

    rot = prime
    tmp = set([rot])
    isCircular = True
    for n in range(k):
        rot = rot//10 + rot%10 * pow(10, k-1)
        if not rot in primeTable:
            isCircular = False
            break
        tmp.add(rot)

    if isCircular:
        res.update(tmp)
time3 = time.time()

print("generate table: {}, sord out circular: {}".format(time1-time0, time3 - time2))
print(len(res))