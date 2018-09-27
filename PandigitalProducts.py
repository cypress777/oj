# Am * Bn = Cm+n where 2*(m + n) = 9
# or Am * Bn = Cm+n+1 2*(m + n) + 1= 9
# =>  m + n = 4
import math
import Permutation as lp

numbers = [i for i in range(1, 10)]
ans = set([])

while (not lp.isEnd(numbers)):
    C = numbers[0] + numbers[1]*10 + numbers[2]*100 + numbers[3]*1000
    A = numbers[4] + numbers[5]*10
    B = numbers[6] + numbers[7]*10 + numbers[8]*100
    if A*B == C:
        ans.add(C)
    A = numbers[4]
    B = numbers[5] + numbers[6]*10 + numbers[7]*100 + numbers[8]*1000
    if A*B == C:
        ans.add(C)
    numbers = lp.nextPermuteStr(numbers)

res = 0
ans = list(ans)
for i in range(len(ans)):
    res += ans[i]

print(res)



