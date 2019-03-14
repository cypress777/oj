mm = 10000000
fin = [-1] * 2 * mm

fin[1] = 1
fin[89] = 89
count = 1

def next(n):
    m = 0
    while n > 0:
        mm = (n % 10)
        m += mm * mm
        n //= 10
    return m

for i in range(1, mm + 1):
    if fin[i] == 1 or fin[i] == 89:
        continue

    j = i
    s = []
    while j != 1 and j != 89:
        if fin[j] == 1 or fin[j] == 89:
            j = fin[j]
            break
        s.append(j)
        j = next(j)

    for ss in s:
        fin[ss] = j
        if j == 89 and ss <= mm:
            count += 1

# count = 0
# for i in range(1, mm + 1):
#     if fin[i] == 89:
#         count += 1

print(count)