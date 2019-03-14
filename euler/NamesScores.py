with open("names.txt") as f:
    names = f.readlines()[0].split(',')
    names = ([x.strip('"') for x in names])

    names.sort(key=str.lower)

    count = 0
    total_value = 0
    for name in names:
        count += 1
        value = 0
        for i in range(len(name)):
            value += ord(name[i]) - ord('A') + 1
        value *= count
        total_value += value

    print(total_value)
