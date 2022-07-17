n,b=input().split()
n,b=int(n),int(b)
points=[[0,0]]*n
print(points)
for j in range(n):
    o,p = input().split()
    points[j][0] =o
    points[j][1]=p
print(points)
ans = 101
for i in range(n):
    xline=points[i][0]
    for j in range(n):
        yline=points[j][1]
        quad=[[0,0],[0,0]]
        for point in points:
            tb=0
            rl=0
            if point[1] <= yline:
                tb=1
            if point[0] >= xline:
                rl=1
            quad[tb][rl]+=1
        # print(xline, yline, quad)
        maximum = max(max(quad[0][0], quad[0][1]), max(quad[1][0], quad[1][1]))
        ans=min(ans,maximum)

print(ans)