#!/usr/bin/python

a, b, c, N = map(int, raw_input().strip().split())

newBorns = 1
ones = 0
twos = 0
threeMores = 0
n = 0

while n < N:
    threeMores += twos
    twos = ones
    ones = newBorns
    newBorns = ones * a + twos * b + threeMores * c
    n += 1

rabbits = newBorns + ones + twos + threeMores

print(rabbits)
