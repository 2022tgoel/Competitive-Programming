inp = [int(x) for x in raw_input().split(" ")]
cd = inp[1]-inp[0]

if cd == inp[2]-inp[1] and cd == inp[3] - inp[2]:
   print inp[3]+cd
   exit()
if inp[0]!= 0:
   cq = float(inp[1])/inp[0]
   if cq!=0.0 and inp[1]*cq == inp[2] and inp[2] * cq == inp[3] and cq*inp[3] == int(cq*inp[3]):
      print int(inp[3]*cq)
      exit()
print 42