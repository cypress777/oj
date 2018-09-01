n = 1001
len = n
sum = 0
while n > 1:
    for i in range(4):
        sum += n*n - i * (n - 1)
    n -= 2
sum += 1

print(sum)