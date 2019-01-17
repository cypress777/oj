matrix = []
class Point(object):
    def __init__(self, x, y):
        super(Point, self).__init__()
        self.x = x
        self.y = y

delta_x = [0, 1, 0]
delta_y = [-1, 0, -1]

f = open('p082_matrix.txt')
lines = f.readlines()
for line in lines:
    s = [int(ss) for ss in line.strip('\n').split(',')]
    matrix.append(s)

row = len(matrix)
col = len(matrix[0])

vst = [[-1] * col] * row
que = []

def up(r, n):
    i = n - r + 1
    j = i // 2
    m = r + j - 1
    pi = que[n]
    pj = que[m]
    while n > r and vst[pi.y][pi.x] < vst[pj.y][pj.x]:
        que[n] = pj
        que[m] = pi
        n = m
        i = n - r + 1
        j = i // 2
        m = r + j - 1
        pi = que[n]
        pj = que[m]

def delete(r, f, n):
    return r, f

r = 0
f = 0
for i in range(row):
    que.append(Point(0, i))
    f += 1
    vst[i][0] = matrix[i][0]
    up(r, f)

while r < len(que):
    id = que[r]
    r, f = delete(r, f, r)
    
    for k in range(3):
        xx = id.x + delta_x[k]
        yy = id.y + delta_y[k]

        if xx >= 0 and xx < col and yy >= 0 and yy < row:
            if vst[yy][xx] == -1:
                vst[yy][xx] = vst[id.y][id.x] + matrix[yy][xx]

                if xx == col - 1:
                    print(vst[yy][xx])
                    exit()

                que.append(Point(xx, yy))
                f += 1
                up(r, len(que) - 1)