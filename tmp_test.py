s1 = input()
s2 = input()

n, x, y = [int(i) for i in s1.split(' ')]
score = []
for s in s2.split(' '):
    score.append(int(s))

h = score[0]
score = score[1 : ]
score.sort(reverse=True)

min_spent = 1000000000000
p = 0
decreased = 0
if n == 1 or h > max(score):
    print(0)
else:
    for h_fin in reversed(range(max(h, min(score) + 1), max(score) + 2)):
        i = 0
        while i < len(score) and score[i] > (h_fin - 1):
            decreased += score[i] - h_fin + 1
            i += 1
        decreased += p
        spent = decreased * y
        p += i
        score = score[i :]

        if h_fin - decreased - h > 0:
            spent += (h_fin - decreased - h) * x
        else:
            continue
        if spent < min_spent:
            min_spent = spent
    print(min_spent)