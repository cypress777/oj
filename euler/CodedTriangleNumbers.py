import math

def isTriangleNum(t):
    dt = 2. * t
    st = math.sqrt(dt)
    if st % 1 == 0:
        return False
    if dt == math.ceil(st) * math.floor(st):
        return True
    else:
        return False


f = open('p042_words.txt')
raw_words = f.readlines()[0]
raw_words = raw_words.split(',')
words = [word.strip('\"') for word in raw_words]

count = 0
for word in words:
    sum = 0
    for letter in list(word):
        sum += (ord(letter) - 64)
    if isTriangleNum(sum):
        count += 1
print (count)

