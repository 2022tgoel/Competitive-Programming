sol = {}
inp = raw_input().split(" ")
color = int(inp[1])
cars = raw_input().split(" ")
acount = 0
for i in cars:
   ccar=int(i)
   if ccar == color:
      acount+=1
      sol = {k: v for k, v in sol.iteritems() if v>=acount}
   else:
      if ccar in sol:
         if sol[ccar]>=acount:
            sol[ccar]+=1
         else:
            del sol[ccar]
      else:
         if acount ==0:
            sol[ccar]=1
if not sol:
   print -1
   exit()
print(next(iter(sol)))