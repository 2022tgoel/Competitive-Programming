len = int(raw_input())
inp = raw_input()

nadd =1
ind = 0
res = ""
while ind<=len-1:
   res+=inp[ind]
   ind+=nadd
   nadd+=1

print res