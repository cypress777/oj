def isEnd(str):
    if len(str) < 2:
        return True
    for i in range(len(str) - 1):
        if str[i] < str[i+1]:
            return False
    return True

def isBegin(str):
    if len(str) < 2:
        return True
    for i in range(len(str) - 1):
        if str[i] > str[i+1]:
            return False
    return True

def nextPermuteStr(str):
    i = -1
    n = len(str)
    while i > -1*n:
        if str[i] < str[i - 1] or str[i] == str[i - 1]:
            i -= 1
        else:
            break
    if i == -1 * n:
        sstr = str[ : ]
        sstr.sort()
        return sstr
    prestr = str[ : i]
    surstr = str[i : ]
    surstr.sort()
    for i in range(0, len(surstr)):
        if surstr[i] > prestr[-1]:
            surstr[i], prestr[-1] = prestr[-1], surstr[i]
            break
    sstr = prestr+surstr
    return sstr

def lastPermuteStr(str):
    i = -1
    n = len(str)
    while i > -1*n:
        if str[i] > str[i - 1] or str[i] == str[i - 1]:
            i -= 1
        else:
            break
    if i == -1 * n:
        sstr = str[ : ]
        sstr.sort(reverse=True)
        return sstr
    prestr = str[ : i]
    surstr = str[i : ]
    for i in range(0, len(surstr)):
        if surstr[len(surstr) - 1 - i] < prestr[-1]:
            surstr[len(surstr) - 1 - i], prestr[-1] = prestr[-1], surstr[len(surstr) - 1 - i]
            break
    surstr.sort(reverse=True)
    sstr = prestr+surstr
    return sstr

if __name__ == '__main__':
    # str = [i for i in range(10)]
    # i = 1
    # while i < 1000000:
    #     str = nextPermuteStr(str)
    #     i += 1
    #
    # print(str)
    str = list('7652413')
    print(str)
    nstr = nextPermuteStr(str)
    print(nstr)
    lstr = lastPermuteStr(nstr)
    print(lstr)