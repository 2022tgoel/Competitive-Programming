def recurse(arr, sum, ind):
   if len(arr)==ind:
      if sum%360 ==0: 
         return 2
      else:
         return -2
   else:
      val = arr[ind]
      ind+=1
      success = recurse(arr, sum-val, ind)
      if success == 2:
         return 2
      success = recurse(arr, sum+val, ind)
      if success == 2:
         return 2
   

n = int(raw_input())
arr = []

for i in range(n):
   arr.append(int(raw_input()))

if recurse(arr, 0, 0) ==2:
   print "YES"
else:
   print "NO"
   