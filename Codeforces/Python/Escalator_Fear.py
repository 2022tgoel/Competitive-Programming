import math

inp = raw_input().split(" ")
num = int(inp[0])
p = float(inp[1])
sec = int(inp[2])

probs = [[0.0 for x in range(sec+1)] for y in range(num+1)] #2d array of probabilities

total = 0.0

#Initializing row 0 vals as 1
for i in range(sec+1):
   probs[0][i]=1.0

for i in range(1, num+1):
   for j in range(1, sec+1):
      probs[i][j] = p * probs[i-1][j-1] + (1-p)*probs[i][j-1]
      if j == sec:
         total+=probs[i][j]

print total
