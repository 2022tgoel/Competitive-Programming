fout = open ('guess.out', 'w')

char = {}
animal = {}
with open('guess.in') as f:
   alist = [line.rstrip() for line in f]
num = int(alist[0])
for i in range(1, len(alist)):
   arr= alist[i].split(" ")
   animal[arr[0]] = tuple(arr[2:len(arr)])
   for trait in arr[2:len(arr)]:
      if trait in char:
         char[trait]+=1
      else:
         char[trait] =1

anim = animal.keys()
c = 0
for i in range(num):
   for j in range (i+1, num):
      a1 = animal[anim[i]]
      a2 = animal[anim[j]]
      counter = 0
      for element in a1:
         if element in a2:
            counter+=1
      c = max(counter, c)
fout.write(str(c+1))