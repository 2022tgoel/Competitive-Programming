'''
Bessie the cow wants to paint a wall that is composed of N×M (1≤N,M≤1,000,000,000) squares. However, she only wants to paint certain squares on the wall. 

Bessie has a very particular way to determine which squares she is going to paint. She paints the center square in the wall; if there is no center square, she stops painting. Then she divides up the wall by using the row and column of the painted center square to separate the wall into four equally sized smaller walls. Then she paints the center squares of each of the smaller walls as before. She keeps painting until there is no center square to paint or the field cannot be divided up any further.

For example, if N=7 and M=23, then Bessie will paint the square at row 4, column 12. Then she divides the wall into four 3x11 fields and paints the square at row 2, column 6, further dividing the wall into 1x5 fields. Then she paints the square at row 1, column 3 in each of the 1x5 fields. The resulting 1x2 walls have no center squares, so the process stops here. This process is depicted below, with P denoting a painted square.

.......................    .....................
.......................    .....................
.......................    .....................
....................... -> ...........P......... ->
.......................    .....................
.......................    .....................
.......................    .....................

...........|...........    ..P..|..P..|..P..|..P..
.....P.....|.....P.....    -----P-----|-----P-----
...........|...........    ..P..|..P..|..P..|..P..
-----------P----------- -> -----------P-----------
...........|...........    ..P..|..P..|..P..|..P..
.....P.....|.....P.....    -----P-----|-----P-----
...........|...........    ..P..|..P..|..P..|..P..
Bessie ends up painting 21 squares on this wall. Determine how many squares on the wall Bessie the cow is going to paint.

INPUT FORMAT

* Line 1: Two space-separated integers: N and M

OUTPUT FORMAT

* Line 1: The number of painted squares.

SAMPLE INPUT

7 23
SAMPLE OUTPUT

21
'''

N, M = [int(x) for x in input().split()]

num = 1
ans = 0

while (N%2==1 and M%2==1):
	ans+=num
	if (N==1 or M==1):
		break
	if N > 1:
		N//=2
		num*=2
	if M > 1:
		M//=2
		num*=2
	

print(ans)