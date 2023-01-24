import random
decide=int(input())
a=random.randint(1,100)
b=random.randint(1,100)
c=random.randint(1,100)
d=random.randint(1,100)
e=random.randint(1,100)
if(decide<4):
    up=random.randint(1,1000)
    print(a,b,c,d,e)
    print(a*up,b*up,c*up,d*up,e*up)
else:
    print(a,b,c,d,e)
    print(a*random.randint(1,1000),b*random.randint(1,1000),c*random.randint(1,1000),d*random.randint(1,1000),e*random.randint(1,1000),end="")