def ToList(num):
    list = []
    while (num > 0):
        list.append(num % 10)
        num //= 10
    return list

def IsPalindrome(list):
    s = 0
    e = len(list) - 1
    while e > s:
        if list[s] != list[e]:
            return False
        s += 1
        e -= 1
    return True

all = []
for n in range(1, 10000):
    is_lychrel = True
    nn = n
    for k in range(0, 50):
        l = ToList(nn)
        rl = l[:]
        rl.reverse()

        rn = 0
        p = 0
        for digit in rl:
            rn += digit * pow(10, p)
            p += 1

        nn += rn
        sl = ToList(nn)
        if IsPalindrome(sl):
            is_lychrel = False
            break
    if is_lychrel:
        all.append(n)
print(len(all))