arr = [None] * int(raw_input())
string = raw_input()
vals = [1] * len(arr)
for i in range(len(arr)-1):
   if string[i] == "=":    
      vals[i+1]=vals[i]
   elif string[i] == "R":
     vals[i+1]=vals[i]+1
   else:
      vals[i+1]=1
      if vals[i]==1:
         vals[i]+=1 # associated with string[i-1]
         for j in range(i,0,-1):
            if string[j-1]=='=':
               vals[j-1]=vals[j]
            elif string[j-1]=='L' and vals[j-1]==vals[j]:
               vals[j-1]+=1
            else:
               break
      
for num in vals:
   print num,