l = 100

sta = [0] * (l + 1)
sta[0] = 1

for k in range(1, l + 1):
    for i in range(1, l + 1):
        if k <= i:
            sta[i] += sta[i - k]

print(sta[l] - 1)