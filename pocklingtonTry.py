import random
p=7
a=random.randint(1,p-1)
x=pow(a,p-1,p**2)
if x % p == 1 and x % (p*p) != 1:
        print(True) 
else:
        print (False) 
