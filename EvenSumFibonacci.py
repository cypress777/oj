import math

phi = (1 + math.sqrt(5)) / 2
k = int(math.log(math.sqrt(5)*4000000 + 0.5, phi))
sum = 1/math.sqrt(5) * ((1 - math.pow(phi, k+1))/(1 - phi) - (1 - math.pow(1-phi, k+1))/phi)
print(sum/2)
