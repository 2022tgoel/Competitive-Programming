inp = raw_input().split(" ")

sum = int(inp[0])
num = int(inp[1])
ans = []
"""
if sum==num:
   print "YES"
   for i in range(num):
      print 1,
   exit()"""
if num>sum:
   print "NO"
   exit()
sum = bin(sum)[2:]

for i in range(len(sum)):
   if sum[len(sum)-i-1]=="1":
      ans.append(2**i)
endadd=[]
c=False
while len(ans)<num:
   while len(ans)+len(endadd)<num and len(ans)>0:
      if ans[len(ans)-1]%2==0:
         x = ans[len(ans)-1]/2
         ans.pop()
         endadd += [x,x]
      else:
         endadd.append(ans.pop())   
   ans+=endadd
   endadd = [] 
   #print ans


if len(ans)!=num:
   print "NO"
else:
   print "YES"
   ans.sort()
   print " ".join(map(str,ans))
 