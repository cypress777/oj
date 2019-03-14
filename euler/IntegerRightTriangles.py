max = 0
max_num = 0
for num in range(1001):
    res = 0
    for c in range(num / 3, num / 2):
        for b in range(1, (num - c) / 2):
            a = num - b - c
            if (a*a + b*b == c*c):
                res += 1
    if res > max:
        max = res
        max_num = num
print(max_num)
