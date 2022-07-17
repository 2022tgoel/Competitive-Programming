x1,y1,x2,y2 = [int(i) for i in input().split()]
x3,y3,x4,y4 = [int(i) for i in input().split()]
x5,y5,x6,y6 = [int(i) for i in input().split()]

# intr1 = (min(x2, x6) - max(x1, x5)) * (min(y2, y6) - max(y1, y5))

intr1 = 0 if (min(x2, x6) - max(x1, x5)) < 0 else  (min(x2, x6) - max(x1, x5)) * (min(y2, y6) - max(y1, y5))
intr2 = 0 if (min(x4, x6) - max(x3, x5)) < 0 else (min(x4, x6) - max(x3, x5)) * (min(y4, y6) - max(y3, y5))
# print(intr1, intr2)
print((x2-x1)*(y2-y1) + (x4-x3)*(y4-y3) - max(0, intr2) - max(0, intr1))
