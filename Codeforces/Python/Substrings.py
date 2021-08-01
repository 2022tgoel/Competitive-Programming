map = {"AB":0, "BA":0,"OTHER":0}
inp = raw_input()

for i in range(len(inp)-1):
   if inp[i:i+2]=="AB":
      map["AB"]+=1
   if inp[i:i+2]=="BA":
      map["BA"]+=1
   if i<len(inp)-2:
      if inp[i:i+3] == "ABA" or inp[i:i+3] == "BAB":
         map["OTHER"]+=1

if map["AB"]+map["BA"]>map["OTHER"]+1 and map["AB"]>=1 and map["BA"]>=1:
   print "YES"
elif map["OTHER"]>=3:   
   print "YES"
else:
   print "NO"