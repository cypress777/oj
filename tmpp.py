res = []
sum = 0
for num in range(1, 1000001):
    if num % 2 == 0:
        continue

    isPan = True

    if str(num) != str(num)[::-1]:
        isPan = False
        continue

    if isPan:
        bnum = bin(num)[2:]
        if bnum != bnum[::-1]:
            isPan = False
            continue

    res.append(num)
    sum += num

print (list(res))
print (sum)