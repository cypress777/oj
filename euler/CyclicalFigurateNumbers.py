p3 = []
p4 = []
p5 = []
p6 = []
p7 = []
p8 = []

for n in range(1, 10000):
    num = n * (n + 1) / 2
    if (num < 10000 and num > 999):
        p3.append(num)
    num = n * n
    if (num < 10000 and num > 999):
        p4.append(num)
    num = n * (3 * n - 1) / 2
    if (num < 10000 and num > 999):
        p5.append(num)
    num = n * (2 * n - 1)
    if (num < 10000 and num > 999):
        p6.append(num)
    num = n * (5 * n - 3) / 2
    if (num < 10000 and num > 999):
        p7.append(num)
    num = n * (3 * n - 2)
    if (num < 10000 and num > 999):
        p8.append(num)

pl = [p3, p4, p5, p6, p7, p8]


def find(l1, l2):
    if len(l1) == 6:
        if l1[5] % 100 == l1[0] // 100:
            print(l1)
            print(sum(l1))
            exit()
        return

    for i in range(0, 6):
        if i in l2:
            continue

        for n in pl[i]:
            if len(l1) == 0 or (len(l1) > 0 and n // 100 == l1[-1] % 100):
                ll1 = l1.copy()
                ll2 = l2.copy()
                ll1.append(n)
                ll2.append(i)
                find(ll1, ll2)

find([], [])