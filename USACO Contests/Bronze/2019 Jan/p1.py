fin = open ('shell.in', 'r')
fout = open ('shell.out', 'w')

swaps = int(fin.readline())
num_c = 0
arr = []
for i in range(swaps):
   arr.append([int(x) for x in fin.readline().split(" ")])

for i in range(1,4):
   num = 0
   corr = i
   for a in arr:
      if a[0] == corr:
         corr =a[1]
      elif a[1] == corr:
         corr =a[0]
      if a[2] == corr:
         num+=1
   num_c = max(num, num_c)

fout.write(str(num_c))
