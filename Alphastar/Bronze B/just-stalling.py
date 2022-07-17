'''
SAMPLE INPUT:
4
1 2 3 4
2 4 3 4
SAMPLE OUTPUT:
8
'''

N = int(input())

h = [int(x) for x in input().split()]
h.sort()
stalls = [int(x) for x in input().split()]
stalls.sort()
mult = [0]*N
num = 0
for i in range(N):
	while stalls[num] < h[i]:
		mult[num] = i-num # number of options
		num+=1

while num < N:
	# i-1 to num are your options
	mult[num] = N-num
	num+=1
# print(mult)

ans = 1
for x in mult:
	ans*=x
print(ans)