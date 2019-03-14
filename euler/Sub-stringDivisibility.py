import Permutation

prime = [0, 2, 3, 5, 7, 11, 13, 17]

num = [str(i) for i in range(10)]
allnums = []
while not Permutation.isEnd(num):
    isPan = True
    for k in range(1, 8):
        if int(''.join(num[k : k + 3]).lstrip('0')) % prime[k] != 0:
            isPan = False
            break

    if isPan:
        print(int(''.join(num)))
        allnums.append(int(''.join(num)))
    num = Permutation.nextPermuteStr(num)

sum = 0
for n in allnums:
    sum += n

print(sum)