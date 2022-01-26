import math

L = 3
S = '123'
C = 678910

start = 1237940039285380274899124224
start_pow = 90
multi = [100433627766186892221372630771322662657637687111424552206336, 994646472819573284310764496293641680200912301594695434880927953786318994025066751066112, 99895953610111751404211111353381321783955140565279076827493022708011895642232499843849795298031743077114461795885011932654335221737225129801285632]
multi_pow = [196, 289, 485]

lower = math.log(123, 2)
upper = math.log(124, 2)

def check(p):
  l = 0
  r = 1000000000
  while l + 1 < r:
    m = (l + r) // 2
    if lower + m * math.log(10, 2) < p:
      l = m
    else:
      r = m
  t = l
  #  print(t, p, lower + t * math.log(10, 2),  upper + t * math.log(10, 2))
  return p < upper + t * math.log(10, 2)

count = 1
power = start_pow
while count < C:
  power += 1
  if check(power):
    count += 1
    if count % 10000 == 0 or count == C:
      print(count, power)

exit()

# Due to precision of python float precision, we missed out one number.
# Please use the second to last result as final result.
count = 1
curr = start
power = start_pow
while count < C:
  for p in multi_pow:
    next = power + p
    if check(next):
      power = next
      count += 1
      break

  if count % 10000 == 0 or count <= C - 5:
    print(count, power)
    # print(curr, '\n')