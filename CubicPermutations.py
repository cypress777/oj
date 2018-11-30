digits = ''
min_cube = float('Inf')
n = 1000
d = 5
cubes = {}

while True:
    c = n*n*n
    digits = ''.join(sorted(str(c)))
    if digits in cubes:
        cubes[digits] += [c]
        if len(cubes[digits]) == d:
            min_cube = cubes[digits][0]
            break
    else:
        cubes[digits] = [c]
    n += 1    

print("Smallest cube = {}".format(min_cube))
