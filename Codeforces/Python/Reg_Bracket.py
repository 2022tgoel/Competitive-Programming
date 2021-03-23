#https://codeforces.com/problemset/problem/5/C

inp = raw_input()
stack = [-1] 
ret = 0
count = 1
for i in range(len(inp)):  
   if inp[i] == '(': 
      stack.append(i) 
   else:
      stack.pop()
      if len(stack) != 0: 
         if i-stack[len(stack)-1]>ret:
            ret =i-stack[len(stack)-1] 
            count =1
         elif i-stack[len(stack)-1]==ret:
            count+=1
      else: 
         stack.append(i) 
print ret, count