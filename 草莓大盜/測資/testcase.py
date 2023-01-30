from random import randint as ran

num = int(input())

if num < 6:
    n = 1
    m = ran(10000,1000000)
elif num < 8:
    n = 2
    m = ran(100000,1000000)
elif num < 11:
    n = ran(90, 100)
    m = 1000000
else:
    n = 1000000
    m = 1000000

N = set()
M = set()

ans = str(n) + " " + str(m)

for i in range(n):
    a = ran(0, 10000000)
    while(a in N):
        a = ran(0, 10000000)
    N.add(a)
    ans += "\n" + str(a) + " " + str(ran(1, 10000))
    
for i in range(m):
    a = ran(0, 10000000)
    while(a in M):
        a = ran(0, 10000000)
    M.add(a)
    ans += "\n" + str(a) + " " + str(ran(1, 1000000000))
print(ans)