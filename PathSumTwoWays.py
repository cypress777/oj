import numpy as np

f = open('p081_matrix.txt', 'r')
matrix = []
lines = f.readlines()
for line in lines:
    s = [int(ss) for ss in line.strip('\n').split(',')]
    matrix.append(s)
matrix = np.array(matrix)