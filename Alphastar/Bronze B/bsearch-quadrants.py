'''
10 20
7 17
19 1
3 5
5 7
5 3
3 7
9 15
15 17
13 15
17 13

output: 4

'''

N, B = [int(x) for x in input().split()]
points = []

for i in range(N):
	x, y = [int(x) for x in input().split()]
	points.append((x, y))

points.sort(key=lambda x: x[1]) # sort by y value

def find_max_quad(xline, yline): 
	# -1 -> above
	# 0 -> both have max
	# 1 -> below
	quad = [[0, 0], 
			[0, 0]]
	for p in points:
		quad[0 if p[1] >= yline else 1][0 if p[0] <= xline else 1] += 1
	signal = 0
	if (max(quad[0]) > max(quad[1])):
		signal = -1
	elif (max(quad[0]) < max(quad[1])):
		signal = 1
	return signal, max(max(quad[0]), max(quad[1]))

def bsearch(xline):
	lo = 0
	hi = len(points) - 1
	ans = 101
	while (lo < hi):
		mid = int((lo + hi) / 2)
		signal, cur = find_max_quad(xline, points[mid][1])
		ans = min(ans, cur)
		if (signal == 0):
			break # you are not going to be better that this by moving up and down
		elif (signal == -1):
			lo = mid+1
		else:
			hi = mid-1
	return ans

ans = 101
for h in range(N):
	xline = points[h][0]
	ans = min(ans, bsearch(xline))
print(ans)