import math

cnt = 0
a, b, c = [0, 0, 0]
for a in range(1, 10000):
    for b in range(1, a + 1):
        for c in range(1, b + 1):
            s = math.sqrt((b + c) * (b + c) + a * a)
            if int(s) == s:
                cnt += 1
            if cnt > 1000000:
                print(a)
                exit()
