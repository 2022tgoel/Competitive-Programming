import math
a, b, c, d = [int(x) for x in raw_input().split(" ")]
count = 0
s = ""
for ax in range(d/a + 1):
   for bx in range(d/b + 1):
      cx = (d - ax * a - bx * b) / c
      if (cx >= 0 and ax * a + bx * b + cx * c == d):
         count += 1
         s += (str( ax) + " " +str( bx) + " "+ str(cx       )) + "\n"
      
if(count == 0):
   print("impossible")
else:
   print(s)