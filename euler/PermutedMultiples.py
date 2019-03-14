num = 1
not_same = True
while not_same:
    not_same = False
    num += 1
    for mult in [2, 3, 4, 5, 6]:
        if set(str(num)) != set(str(num * mult)):
            not_same = True
            break
    if not not_same:
        break
print(num)