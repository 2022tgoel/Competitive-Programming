'''
Since it has not been raining very long, the puddles can be shown on a diagram of the field as either one ‘#’ symbol or two adjacent ‘#’ symbols (not including diagonals). All parts of the field with no puddles are shown as a ‘.’ symbol. Using a diagram of the field, help Bessie determine the number of puddles in the field.

For example, Bessie has this diagram of a field with R = 6 rows and C = 8 columns:

......#.
.#...#..
.#.....#
...##..#
#.......
.#..#.##
This field has a total of 9 puddles as shown below: one on the row 1 column 7, one on rows 2 and 3 of column 2, one on row 2 column 6, one on rows 3 and 4 of column 8, one on row 4 columns 4 and 5, one on row 5 column 1, one on row 6 column 2, one on row 6 column 5, and one on row 6 columns 7 and 8.

......1.
.2...3..
.2.....4
...55..4
6.......
.7..8.99
INPUT FORMAT

* Line 1: Two space-separated integers: R and C
* Line 2…. R + 1: Line i + 1 has C characters that are either a ‘.’ or a ‘#’, which describe the i th row of the field.

OUTPUT FORMAT

* Line 1: A single integer representing the number of puddles on the field

SAMPLE INPUT

6 8
......#.
.#...#..
.#.....#
...##..#
#.......
.#..#.##
SAMPLE OUTPUT

9
'''

R, C = [int(x) for x in input().split()]

grid = [" "*(C+2)]

for i in range(R):
	grid.append(" " + input() + " ")

grid.append(" "*(C+2))

c = 0

for i in range(1, R+1):
	for j in range(1, C+1):
		if grid[i][j] == "#" and grid[i][j-1] != "#" and grid[i-1][j] != "#":
			c+=1

print(c)
