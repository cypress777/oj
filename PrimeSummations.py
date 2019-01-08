import MathUtils as mu

prime_tab = mu.genPrimeTab(1000)

thres = 5000

def cal_ways(n):
    ways = [0] * (n + 1)
    ways[0] = 1

    for p in prime_tab:
        if p > n:
            break
        for i in range(p, n + 1):
            ways[i] += ways[i - p]
    return ways

ways = cal_ways(10000)
for i in range(len(ways)):
    if ways[i] > 5000:
        print(i, ways[i])
        break
