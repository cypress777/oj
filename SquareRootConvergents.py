n = [1]
m = [2]
for k in range(1, 1000):
    n.append(m[k - 1])
    m.append(2 * m[k - 1] + n[k - 1])

sum = 0
for i in range(0, 1000):
    nu = m[i] + n[i]
    de = m[i]
    if len(str(nu)) > len(str(de)):
        sum += 1
print(sum)