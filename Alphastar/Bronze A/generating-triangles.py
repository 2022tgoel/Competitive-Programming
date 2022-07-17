N, S = [int(x) for x in input().split()]

def add(x, y):
	s = x+y 
	while (s > 9):
		s-=9
	return s

triangle = []
for i in range(N):
	triangle.append([0]*N)

triangle[0][0] = S
for i in range(1, N):
	triangle[0][i] = add(triangle[0][i-1], i)

for j in range(0, N):
	for i in range(1, j+1):
		triangle[i][j] = add(triangle[i-1][j], 1)
# print(triangle)
for i in range(N):
	for j in range(N):
		if (triangle[i][j] == 0):
			print(" ", end=" ")
		else:
			print(triangle[i][j], end=" ")
	print()