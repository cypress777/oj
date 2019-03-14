#10^7 > 9^5 * 7; 10^6 < 9^5 * 6

numPow5 = [pow(i, 5) for i in range(0, 10)]

ans = 0

for i in range(2, pow(10, 6)):
    num = i
    sum = 0
    while num != 0:
        sum += numPow5[num % 10]
        num /= 10
    if sum == i:
        ans += i
        print(i)

print("ans: {}".format(ans))

