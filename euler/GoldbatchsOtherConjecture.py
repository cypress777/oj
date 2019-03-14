import math
import MathUtils

prime_tab = MathUtils.genPrimeTab(100000)
print(len(prime_tab))

def IsGoldbachNum(num):
    if num % 2 == 0:
        return False

    index = 0;
    while(prime_tab[index] <= num):
        n = math.sqrt((num - prime_tab[index]) / 2)
        if int(n) == n:
            return True
        index = index + 1

    return False

guess = 33
while guess < 100000 and IsGoldbachNum(guess):
    guess = guess + 2

print('result: ', guess)