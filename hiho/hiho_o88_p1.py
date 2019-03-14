n = int(input())

def xxx(l):
    if len(l) == n:
        o = ''
        for i in range(len(l)):
            if i < len(l) - 1:
                o += str(l[i]) + ' '
            else:
                o += str(l[i])
        print(o)
    else:
        for i in range(1, n + 1):
            if not i in l and (len(l) == 0 or (i + l[-1]) % 2 != 0):
                ll = l[:]
                ll.append(i)
                xxx(ll)

xxx([])