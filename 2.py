import random
p = int(input())
b = 0
while (((p - 1) % 2**b)==0):
    b += 1
m = (1-p)/2**b
a = random.randint(0, p-1) 
j =0
z = (a * m) % p
if z == 1 or z == p-1:
    print("Prime Number")