'''
Cow Covering
Recently, it has been raining a lot on Farmer John’s farm. For this reason, his N (3 <= N <= 50,000) cows refuse to go outside. Farmer John’s cows all prefer to graze on a certain part of his field, and their milk production increases when they graze on their preferred grass, so Farmer John decides to build a rectangular structure over part of his field to keep the cows dry. Farmer John already has a covering that will keep any one of his cows dry, so he only needs to build a structure to cover the remaining N-1 cows. Find the area of the smallest structure he can build to keep his cows dry. 

In this problem, cows can be viewed as points between 1 and 40,000 on a coordinate plane, and the cows on the border of the structure are considered as covered. There can be a structure with a zero area if all the cows are located on the same point.

INPUT FORMAT

The first line of the input contains one space separated integer N. The next N lines each contain two space separated integers describing the coordinates of the cow.

OUTPUT FORMAT

A single integer describing the minimum area of a structure that Farmer John could build to cover N-1 of his cows.

SAMPLE INPUT

5
1 7
10 2
6 12
8 20
3 10
SAMPLE OUTPUT

90
'''

N = int(input())
x = []
y = []

for i in range(N):
	a, b = [int(x) for x in input().split()]
	x.append(a)
	y.append(b)

if (N==1):
	print(0)
	exit()

def compute_cow(points, fn):
	ans = 0
	for i in range(len(points)):
		if (fn(points[ans], points[i]) != points[ans]):
			ans = i
	return ans

def area(x, y, exclude):
	minx, miny = 1000000, 1000000
	maxx, maxy = -1,-1
	for i in range(len(x)):
		if i == exclude:
			continue
		minx = min(minx, x[i])
		maxx = max(maxx, x[i])
		miny = min(miny, y[i])
		maxy = max(maxy, y[i])
	return (maxx-minx)*(maxy-miny)

exclude = [compute_cow(x, min), compute_cow(x, max), compute_cow(y, min), compute_cow(y, max)]
# print(exclude)
ans = 10000000000

for val in exclude:
	ans = min(ans, area(x, y, val))

print(ans)