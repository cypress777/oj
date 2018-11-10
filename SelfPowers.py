import math

def LastTenDigitPow(num):
    last_ten_digit = num
    times = 1
    while times < num:
        last_ten_digit *= num
        last_ten_digit = last_ten_digit % math.pow(10, 10)
        times += 1
    return last_ten_digit

last_ten_digit = 0
for i in range(1, 1000):
    last_ten_digit += LastTenDigitPow(i)
    last_ten_digit = last_ten_digit % math.pow(10, 10)
print(last_ten_digit)