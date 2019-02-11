import math

max_k = 12000
min_k = [999999] * (max_k + 1)

def valid(n, k):
    if k > max_k:
        return False
    if min_k[k] > n:
        min_k[k] = n
        return True
    return False

def calc(n, p, s, d):
#     print(n, p, s, d, min_f)
    if p == 1:
        if valid(n, d + s - 1):
            return 1
        else:
            return 0
    res = 0
    if d > 1:
        if p == s:
            if valid(n, d):
                return 1
            else:
                return 0
        if valid(n, d + s - p):
            res += 1
    
    for i in range(int(math.sqrt(p)), 1, -1):
        if p % i == 0:
            res += calc(n, p // i, s - i, d + 1)
    return res

found = 0
remain = max_k - 1
total = 0
for n in range(4, 2 * max_k + 1):
    found = calc(n, n, n, 1)
#     print(n, found)
    if found > 0:
        remain -= found
        total += n
        if remain < 1:
            break
print(total)
