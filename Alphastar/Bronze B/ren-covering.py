import math

x, y = [int(i) for i in input().split()]

def A(i):
    if i == 1:
        return 1
    else:
        return 3 * (2 ** (i-2))
dis = 0
i = 0
while not (min(x + (-2)**(i),x) <= y and y <= max(x + (-2)**(i),x)):
    i += 1
    # print("on iteration:", i, "traveling", A(i), "new coordinate", x + (-2)**(i-1))
    dis += A(i)

dis += A(i+1) - abs(y - (x + (-2)**(i)))# 1 + 3 + 6 + 12 
print(dis)



'''
x, y = [int(i) for i in input().split()]

def A(i):
    if i == 1:
        return 1
    else:
        return 3 * (2 ** (i-2)) 
def pos(i):
    return x + (-2)**(i-1)
    
dis = 0
i = 0

while (min(pos(i+1),x) <= y and y <= max(pos(i+1),x)) == False:
    i += 1
    dis += A(i)
dis += A(i)
dis -= abs(y - (x + (-2) ^ (i)))
print(dis)
'''

n = int(input())
cows = []
for i in range(n):
    cow = [int(i) for i in input().split()]
    cows.append(cow)

minx = 0
maxx = 0
for i in range(n):
    if cows[maxx][1] < cows[i][1]:
        maxx = i
    if cows[minx][0] > cows[i][0]:
        minx = i

miny = 0
maxy = 0
for i in range(n):
    if cows[maxy][1] < cows[i][1]:
        maxy = i
    if cows[miny][1] > cows[i][1]:
        miny = i 
        
def area(i):
    minx = 1000000000
    miny = 1000000000
    maxx = 0
    maxy = 0
    for j in range(n):
        if i != j:
            minx = min(minx, cows[j][0])
            miny = min(miny, cows[j][1])
            maxx = max(maxx, cows[j][0])
            maxy = max(maxy, cows[j][1])
    return (maxx-minx) * (maxy-miny)

ans = min(area(maxx), area(maxy), area(miny), area(minx))