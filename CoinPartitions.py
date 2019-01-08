MM = 1000000

def cal_ways(n):
    ways = [0] * (n + 1)
    ways[0] = 1

    for p in range(1, n + 1):
        if p > n:
            break
        for i in range(p, n + 1):
            ways[i] += ways[i - p]
            ways[i] %= MM
    return ways

ways = cal_ways(100000)
print(ways[5])
for i in range(len(ways)):
    if ways[i] == 0:
        print(i)
        break
