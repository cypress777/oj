import numpy as np

pyramid = np.zeros([15, 15])
pyramidSum = np.zeros([15, 15])

def maxPath(m, n):
    assert m > 0 or m == 0
    assert n > 0 or n == 0

    if pyramidSum[m][n] != 0:
        return pyramidSum[m][n]

    if m == 14:
        pyramidSum[m][n] = pyramid[m][n]
        return pyramidSum[m][n]

    if pyramidSum[m][n] == 0:
        pyramidSum[m][n] = pyramid[m][n] + max(maxPath(m+1, n), maxPath(m+1, n+1))
        return pyramidSum[m][n]


with open("pyramidI.txt") as f:
    nums = f.readlines()
    nums = [x.strip() for x in nums]

    pyramid = np.zeros([15, 15])

    for i in range(15):
        row = [int(x) for x in nums[i].split(" ")]
        for j in range(i+1):
            pyramid[i][j] = row[j]

    print(maxPath(0, 0))
    print(pyramidSum)