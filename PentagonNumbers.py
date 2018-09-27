def P(n):
    return n * (3 * n - 1) / 2

def isPen(num):
    i = 1
    while i * (3 * i - 1) / 2.0 <= num:
        if i * (3 * i - 1) / 2.0 == num:
            return True
        i += 1
    return False

i = 2
while True:
    print("now: ", i)
    for j in range(1, i):
        if isPen(P(i) + P(j)) and isPen(P(i) - P(j)):
            print(P(i) - P(j))
            exit()
    i += 1