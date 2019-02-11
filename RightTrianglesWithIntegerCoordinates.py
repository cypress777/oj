mm = 50

count = 0
same = 0
for x1 in range(0, mm + 1):
    for y1 in range(0, mm + 1):
        aa = y1 * y1 + x1 * x1
        if aa == 0:
            continue
        for x2 in range(0, mm + 1):
            for y2 in range(0, mm + 1):
                bb = y2 * y2 + x2 * x2
                cc = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)
                if bb == 0 or cc == 0:
                    continue
                if aa + bb == cc or aa + cc == bb or bb + cc == aa:
                    count += 1
print(count // 2)