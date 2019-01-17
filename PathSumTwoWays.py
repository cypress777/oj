f = open('p081_matrix.txt')
lines = f.readlines()
matrix = []
for line in lines:
    s = [int(ss) for ss in line.strip('\n').split(',')]
    matrix.append(s)

row = len(matrix)
col = len(matrix[0])

res = [[0] * 80] * 80

for i in range(row - 1, -1, -1):
    for j in range(col - 1, -1, -1):
        if i == row - 1 and j == col - 1:
            res[i][j] = matrix[i][j]
        elif i == row - 1:
            res[i][j] = matrix[i][j] + res[i][j + 1]
        elif j == col - 1:
            res[i][j] = matrix[i][j] + res[i + 1][j]
        else:
            res[i][j] = matrix[i][j] + min(res[i + 1][j], res[i][j + 1])
print(res[0][0])
