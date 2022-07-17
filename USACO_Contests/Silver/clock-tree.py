'''
SAMPLE INPUT:
4
11 10 11 11
1 2
2 3
2 4
SAMPLE OUTPUT:
1
'''
from collections import defaultdict

ans = 0

adj = defaultdict(lambda:[])

with open("clocktree.in", "r") as f:
	N = int(f.readline())
	time = [int(x) for x in f.readline().split()]

	for i in range(N-1):
		x, y = [int(x) for x in f.readline().split()]
		x-=1; y-=1
		adj[x].append(y)
		adj[y].append(x)

def works(node):
	global ans
	sum = DFS(node, [False]*N)
	if (sum == 0 or sum == 11):
		ans+=1

def DFS(node, visited):
	visited[node] = True 
	s = time[node]
	for nxt in adj[node]:
		if not visited[nxt]:
			s+=DFS(nxt, visited)
	s%=12
	return (12-s)%12

for node in range(N):
	works(node)

with open("clocktree.out", "w") as f:
	f.write(str(ans))