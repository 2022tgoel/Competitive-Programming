#https://www.geeksforgeeks.org/find-two-numbers-sum-xor/
sum = int(raw_input())
xor = int(raw_input())

a = (sum-xor)/2
b = sum-a

if a^b==xor:
   print a,b
else:
   print -1



