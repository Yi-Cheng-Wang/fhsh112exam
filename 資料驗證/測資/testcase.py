import random
num=input()
n1,n2,n3=num.split(" ",3)
n1=int(n1)
n2=int(n2)
n3=int(n3)
print(n1,n2,n3)
counter=n1*(n2+1)
for i in range(counter):
    print(random.randint(0,1),end="")