'''
Quadrants
Farmer John is wondering what type of grass is best for feeding his N (1 <= N <= 100) cows. To do this, he wants to divide his farm up into quadrants, and plant a different type of grass in each quadrant. For his study, he wants to make sure that each quadrant has a similar number of cows. Specifically,he wants to minimize the maximum number of cows in any of the quadrants. Farmer John’s cows are at coordinates (x_i, y_i), where x_i and y_i are positive odd integers from 1 to B. For the first five test cases, B is at most 100. For the rest of the test cases, B is at most 1,000,000. Help Farmer John determine the smallest maximum number of cows in any of the quadrants.

INPUT FORMAT

The first line of the input contains two space separated integers, N and B. The next N lines contain two space separated integers,  x_i and y_i.

OUTPUT FORMAT

The smallest possible value of the maximum number of cows in any of the quadrants.

SAMPLE INPUT

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
SAMPLE OUTPUT

4
If we divide the quadrants up at x = 11 and at y = 11, we get 4 cows in the bottom left quadrant, 2 cows in the top left quadrant, 3 cows in the top right quadrant, and 1 cow in the bottom right quadrant.
'''

N, B = [int(x) for x in input().split()]
points = []

for i in range(N):
	x, y = [int(x) for x in input().split()]
	points.append((x, y))


ans = 101
for h in range(N):
	last = -1
	for v in range(N):
		xline = points[h][0]
		yline = points[v][1]
		quad = [[0, 0], [0, 0]]
		for p in points:
			quad[0 if p[0] <= xline else 1][0 if p[1] <= yline else 1] += 1
		cur = max(max(quad[0]), max(quad[1]))
		if (last != -1 and last < cur):
			break
		ans = min(ans, cur)
print(ans)