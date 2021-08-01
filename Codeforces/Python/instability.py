len = int(raw_input())
arr = [int(x) for x in raw_input().split(" ")]
arr.sort()

if len==1:
   print 0
elif len==2:
   print 0
elif len==3:
   print min(arr[2]-arr[1], arr[1]-arr[0])
else:
   print min(arr[len-1]-arr[1], arr[len-2]-arr[0])
