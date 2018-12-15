import MathUtils as mu

e = [2]
for i in range(1, 100):
    if (i - 1) % 3 == 1:
        e.append(((i - 1) // 3 + 1) * 2)
    else:
        e.append(1)

def upgrade(m, n, d):
    n = m * d + n
    g = mu.gcd(n, d)
    return n // g, d // g

def cal(n):
    if n == 1:
        return e[0], 1

    n -= 1
    nu = 1
    de = e[n]
    while n > 1:
        de, nu = upgrade(e[n - 1], nu, de)
        n -= 1
    nu, de = upgrade(e[0], nu, de)
    return nu, de

for i in range(1, 11):
    print(cal(i))

nu = cal(100)[0]
sum = 0
while nu > 0:
    sum += nu % 10
    nu //= 10
print(sum)