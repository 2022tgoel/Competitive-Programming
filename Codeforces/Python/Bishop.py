num = int(raw_input())
count = 0
mapsum={}
mapdiff={}

for i in range(num):
   pos = raw_input().split(" ")
   s = int(pos[0])+int(pos[1])
   d = int(pos[0])-int(pos[1])
   if s not in mapsum:
      mapsum[s] =0
   if d not in mapdiff:
      mapdiff[d] =0
   mapsum[s]+=1
   mapdiff[d]+=1
   count+=mapsum[s]-1
   count+=mapdiff[d]-1
   
      
print count     