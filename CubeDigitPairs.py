import copy

combinations = []

def is_valid(a, b):
    if (not (0 in a and 1 in b or 1 in a and 0 in b) or
            not (0 in a and 4 in b or 4 in a and 0 in b) or
            not (0 in a and (6 in b or 9 in b) or (6 in a or 9 in a) and 0 in b) or
            not (1 in a and (6 in b or 9 in b) or (6 in a or 9 in a) and 1 in b) or
            not (2 in a and 5 in b or 5 in a and 2 in b) or
            not (3 in a and (6 in b or 9 in b) or (6 in a or 9 in a) and 3 in b) or
            not (4 in a and (6 in b or 9 in b) or (6 in a or 9 in a) and 4 in b) or
            not (1 in a and 8 in b or 8 in a and 1 in b)):
        return False
    return True

def gen_combination(comb, i):
    if len(comb) == 6:
        combinations.append(comb)
    else:
        for num in range(i, 10):
            ncomb = copy.deepcopy(comb)
            ncomb.add(num)
            gen_combination(ncomb, num + 1)

gen_combination(set([]), 0)

count = 0
for i in range(len(combinations)):
    for combj in combinations[i:]:
        if is_valid(combinations[i], combj):
            count += 1
print(count)