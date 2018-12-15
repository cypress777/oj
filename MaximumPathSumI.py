import numpy as np

S = 100

pyramid = np.zeros([S, S])
pyramidSum = np.zeros([S, S])

def maxPath(m, n):
    assert m > 0 or m == 0
    assert n > 0 or n == 0

    if pyramidSum[m][n] != 0:
        return pyramidSum[m][n]

    if m == S - 1:
        pyramidSum[m][n] = pyramid[m][n]
        return pyramidSum[m][n]

    if pyramidSum[m][n] == 0:
        pyramidSum[m][n] = pyramid[m][n] + max(maxPath(m+1, n), maxPath(m+1, n+1))
        return pyramidSum[m][n]


with open("p067_triangle.txt") as f:
    nums = f.readlines()
    nums = [x.strip() for x in nums]

    pyramid = np.zeros([S, S])

    for i in range(S):
        row = [int(x) for x in nums[i].split(" ")]
        for j in range(i+1):
            pyramid[i][j] = row[j]

    print(maxPath(0, 0))
    print(pyramidSum)