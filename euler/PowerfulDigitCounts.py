X = [i for i in range(1, 10)]

count = 0
for x in X:
    n = 1
    nn = x
    mx = 1
    while nn >= mx:
        if nn < mx * 10:
            count += 1
        n += 1
        nn *= x
        mx *= 10
print(count)