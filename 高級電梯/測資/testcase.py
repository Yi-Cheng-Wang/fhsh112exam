from random import randint as ran

num = int(input())
if num < 10:
    n = 2
else:
    n = ran(3, 100)
if num < 10:
    H = 100
else:
    H = 100000
m = ran(1,H)

N = []
for i in range(n):
    a = ran(1,H)
    while a in N:
        a = ran(1,H)
    N.append(a)
if num < 5:
    N.sort()

print(n, m)
for i in N:
    print(i, end=" ");
print("")
for i in range(m):
    print(ran(1,H), end=" ");
