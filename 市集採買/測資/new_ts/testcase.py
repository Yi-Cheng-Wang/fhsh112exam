from random import randint as ran

def pnt(p):
    global tree
    print(tree[p], end=" ")
    if(tree[p]):
        pnt(p*2)
        pnt(p*2+1)
    return
num = int(input())
if(num<=3):
    d=10
elif(num<=9):
    d=15
elif(num<=19):
    d=20
else:
    d=23
m = 100000
bag = ran((d*m)//4, (d*m)//3)
print(bag)
r = 2**(d-1)
p = ran(10,1000)
tree = [[0, ran(1, m)][ran(0, p)>0] for i in range(1, r)]
tree += [0 for i in range(r+1)]

pnt(1)
