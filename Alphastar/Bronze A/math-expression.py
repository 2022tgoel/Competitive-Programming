'''
Math Expression
Given up to 20 possible integer values for each of the variables S,O,M,E,B,I,G, determine how many ways values can be assigned to the variables so the expression (O+M+O)(S+I+S+B+E+E)(E+G+O+S) evaluates to an even number.

INPUT FORMAT

* Line 1: A single integer N
* Line 2 ... N + 1: A variable and a possible value between -300 and 300 for the variable. Each variable will appear between 1 and 20 times and each possible value is unique.

OUTPUT FORMAT

A single integer representing the number of ways values can be assigned to the variables so the expression yields an even answer.

SAMPLE INPUT

12
S 5
E 3
S 7
I 8
O -4
B 12
G -10
O 9
M 1
B -11
B 17
G 6
SAMPLE OUTPUT

16
There are 16 ways we can assign variables to yield an even result:

(S,O,M,E,B,I,G) = (5, -4, 1, 3, 12, 8, -10) -> 1,512
                = (5, 9, 1, 3, 12, 8, -10) -> 4,788
                = (5, -4, 1, 3, 12, 8, 6) -> -2,520
                = (5, 9, 1, 3, 12, 8, 6) -> 15,732
                = (7, -4, 1, 3, 12, 8, -10) -> 1,120
                = (7, 9, 1, 3, 12, 8, -10) -> 6,840
                = (7, -4, 1, 3, 12, 8, 6) -> -3,360
                = (7, 9, 1, 3, 12, 8, 6) -> 19,000
                = (5, -4, 1, 3, -11, 8, -10) -> 546
                = (5, -4, 1, 3, -11, 8, 6) -> -910
                = (7, -4, 1, 3, -11, 8, -10) -> 476
                = (7, -4, 1, 3, -11, 8, 6) -> -1,428
                = (5, -4, 1, 3, 17, 8, -10) -> 1,722
                = (5, -4, 1, 3, 17, 8, 6) -> -2,870
                = (7, -4, 1, 3, 17, 8, -10) -> 1,260
                = (7, -4, 1, 3, 17, 8, 6) -> -3,780
'''


letters = "SOMEBIG"
mp = {}
for char in letters:
	mp[char] = [0, 0]

N = int(input())
for i in range(N):
	char, val = input().split()
	val = int(val)
	if val%2 == 0:
		mp[char][0]+=1
	else:
		mp[char][1]+=1

total = 1
for char in letters:
	total*=sum(mp[char])
# print(total)
ex1 = mp["M"][1]
ex2 = mp["I"][0]*mp["B"][1]+mp["B"][0]*mp["I"][1]
ex3 = 0
x= "EGOS"
for char1 in x:
	count1 = 1 # only even 
	count2 = 1 # only odd
	for char2 in x:
		if (char1 == char2):
			count1*=mp[char2][0]
			count2*=mp[char2][1]
		else:
			count1*=mp[char2][1]
			count2*=mp[char2][0]
	ex3+=count1+count2
# print(ex1, ex2, ex3)
print(total-ex1*ex2*ex3)