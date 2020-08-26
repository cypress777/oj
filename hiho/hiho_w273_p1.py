import numpy as np
import copy

sn = list(raw_input())
raw = copy.deepcopy(sn)

line = raw_input().split()
X = int(line[0])
Y = int(line[1])

if len(sn) == 1 and sn[0] == "?" and Y == 0:
    print("0")
    exit()

ori = 0
for i in range(len(raw)):
    if raw[i] == "?":
        ori = ori * 10
        if i == 0:
            ori = 1
    else:
        ori = ori * 10 + int(raw[i])

sn.reverse()
places = []
for i in range(len(sn)):
    if sn[i] == "?":
        places.append(i)

f = np.zeros((len(places) + 1, X + 1))
a = np.zeros((len(places) + 1, X + 1))
f[0][ori % X] = 1

for i in range(len(places)):
    start = 0
    end = 10
    if places[i] == len(sn) - 1:
        start = 1

    for r in range(X):
        for j in range(start, end):
            if f[i][(r - j * pow(10, places[i]) % X + X) % X] == 1:
                a[i + 1][r] = j
                f[i + 1][r] = 1
                break

if f[len(places)][Y] == 1:
    res = 0
    cnt = len(places)
    rem = Y

    for i in range(len(raw)):
        if raw[i] == "?":
            res = res * 10 + a[cnt][rem]
            cnt -= 1
            rem = int((rem - a[cnt][rem] * pow(10, len(raw) - 1 - i) % X + X) % X)
        else:
            res = res * 10 + int(raw[i])

    print(int(res))
else:
    print("No solution")