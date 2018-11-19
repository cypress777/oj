max = 0
for a in range(1, 100):
    for b in range(1, 100):
        sum = 0
        for i in str(pow(a, b)):
            sum += int(i)
        if sum > max:
            max = sum
print(max)