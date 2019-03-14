def distinctPowers():
    allNumber = set()
    for i in range(2,101):
        temp = i
        for j in range(2,101):
            temp *= i
            allNumber.add(temp)
    return len(allNumber)

print(distinctPowers())