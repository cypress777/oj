def isPen(num):
    i = 1
    while i * (3 * i - 1) <= 2 * num:
        if i * (3 * i - 1) / 2.0 == num:
            return True
        i += 1
    return False

def isHex(num):
    i = 1
    while i * (2 * i - 1) <= num:
        if i * (2 * i - 1) == num:
            return True
        i += 1
    return False

n = 286
while True:
    tri = n * (n + 1) / 2.0
    print(tri)
    if isPen(tri) and isHex(tri):
        print(tri)
        break
    n += 1

