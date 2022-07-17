'''
Acorn Stockpile
Harry the squirrel is storing N (N <= 1000) acorns for winter. He likes his acorns to be similar in size, so he will not include two acorns if their size difference is more than X (he will keep them if the difference is equal to X). Given X, calculate the maximum number of acorns that Harry can store in his nest. 

INPUT FORMAT

The first line of the input file contains N and X (0 <= X <= 10,000). The next N lines each contain an integer giving the size of one of the acorns. All sizes are positive and not bigger than 10,000.

OUTPUT FORMAT

Output a single positive integer that indicates the maximum number of acorns that Harry will have in his nest for winter. 

SAMPLE INPUT

6 2
2
6
3
4
1
4
SAMPLE OUTPUT

4
'''

N, X = [int(x) for x in input().split()]

counts = [0]*(10001)

for i in range(N): # o(n)
	counts[int(input())]+=1


s = sum(counts[0:X+1])
ans = s 

for i in range(1, 10001-X):
	s += counts[i+X] - counts[i-1]
	ans = max(ans, s)

print(ans)