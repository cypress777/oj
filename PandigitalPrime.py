import MathUtils
import Permutation as permutation

num = 987654321
max = 2
while num > 0:
    if MathUtils.isPrime(num):
        max = num
        print("max prime: {}".format(num))
        break

    if permutation.isBegin(list(str(num))):
        num = list(str(num / 10)).sort(reverse=True)
        num = int(str(num))
    else:
        num = int(''.join(permutation.lastPermuteStr(list(str(num)))))