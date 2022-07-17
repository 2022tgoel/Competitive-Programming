'''
SAMPLE INPUT

6
6
3
9
5
7
100
SAMPLE OUTPUT

5
'''

N = int(input())

num = []

for i in range(N):
	num.append(int(input()))

num.sort()
# print(num)
ans = 1
for start in range(N):
	infectedR = 1
	days = 1
	maxend = num[start] + days
	while (start+infectedR < N and num[start+infectedR] <= maxend):
		infectedR+=1
		if (start+infectedR < N and num[start+infectedR] > maxend):
			days+=1
			maxend = num[start+infectedR-1] + days

	infectedL = 1
	days = 1
	maxend = num[start] - days
	while (start-infectedL >= 0 and num[start-infectedL] >= maxend):
		infectedL+=1
		if (start-infectedL >= 0 and num[start-infectedL] < maxend):
			days+=1
			maxend = num[start-infectedL+1] - days

	# print(start, infectedL, infectedR)
	ans = max(ans, infectedL+infectedR-1)

print(ans)