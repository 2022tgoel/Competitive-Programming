# usaco problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=509
from math import sqrt

def conv_dec(x, b):
	x = str(x)
	return int(x[0])*b**2 + int(x[1])*b + int(x[2])

def quadratic(a, b, c):
	disc = b**2 - 4*a*c 
	if (disc >= 0):
		x1 = (-b + sqrt(disc)) / 2 / a 
		x2 = (-b - sqrt(disc)) / 2 / a 
		if (int(x1) == x1 and x1 >= 10):
			# print(x1, x2)
			return x1
		if (int(x2) == x2 and x2 >= 10):
			return x2
	return -1

def solve(x, y):
	for i in range(10, 15001):
		N = conv_dec(x, i)
		y = str(y)
		j = quadratic(int(y[0]), int(y[1]), int(y[2]) - N)
		if (j!=-1):
			# print(N)
			return int(i), int(j)
	return 0, 0 # should never reach this point
with open("whatbase.in", "r") as f1,  open("whatbase.out", "w") as f2:
	T = int(f1.readline())
	for i in range(T):
		x, y = [int(x) for x in f1.readline().split()]
		b1, b2 = solve(x, y)
		f2.write(str(b1) + " " + str(b2) + '\n')
