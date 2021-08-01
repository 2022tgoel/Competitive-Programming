fin = open ('sleepy.in', 'r')
fout = open ('sleepy.out', 'w')

nc = int(fin.readline())
cow = [int(x) for x in fin.readline().split(" ")]
l_asc = 1
last = cow[nc-1]
for i in range(nc-2, -1, -1):
   if cow[i]<last:
      l_asc+=1
      last = cow[i]
   else:
      break

fout.write(str(nc-l_asc)) 
fout.close()