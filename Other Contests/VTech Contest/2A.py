import math
a, b, c = raw_input().split(" ")
a = int(a)
b = int(b)
c = int(c)
h=0
jumps = 0
while h<c:
   jumps += 1
   h+=a
   if h>=c:
      break
   h-=b
print jumps