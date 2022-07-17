def comp(c):
    return c[1]

def comp1(c):
    return c[2]

n = int(input())

cows = [0]*n

for i in range(n):
    x,y = input().split()
    x = int(x)
    y = int(y)
    cows[i] = [i,x,y]

cowsx = cows
cowsy = cows

cowsx = sorted(cowsx,key = comp, reverse=True)

cowsy = sorted(cowsy,key = comp1,reverse=True)

print(cowsx)
#------

print(min((cowsx[1][1]-cowsx[n-1][1])*(cowsy[0][2] - cowsy[n-1][2]),
    (cowsx[0][1] - cowsx[n-2][1])*(cowsy[0][2] - cowsy[n-1][2]),
    (cowsx[0][1] - cowsx[n-1][1])*(cowsy[1][2] - cowsy[n-1][2]),
    (cowsx[0][1] - cowsx[n-1][1])*(cowsy[0][2] - cowsy[n-2][2])))
 