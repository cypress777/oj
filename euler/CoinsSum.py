pocket = [1, 2, 5, 10, 20, 50, 100, 200]

def fill(i, remain):
    if i < 0:
        return 0
    elif remain == 0:
        return 1

    while remain < pocket[i]:
        i -= 1

    return fill(i, remain - pocket[i]) + fill(i - 1, remain)

print(fill(7, 200))