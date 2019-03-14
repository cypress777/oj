res = 1
for i in range(100):
    res *= i+1

print(res)

sum = 0
while res != 0:
    sum += res%10
    res //= 10

print(sum)