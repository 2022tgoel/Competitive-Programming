'''
After a hard day of harvesting crops, Farmer John realizes that he can no longer harvest crops without hurting his back, so he purchases a crop harvester that will automatically harvest crops for him.  However, the crop harvester can only harvest rectangular areas of his field, and Farmer John does not want to have to continuously reposition and recalibrate the crop harvester.So he wants to figure out what rectangular area he wants to have the crop harvester run on. Farmer John’s crops can be mapped to a coordinate plane as two overlapping rectangles with integer coordinates between -1000 and 1000. Given that Farmer John already finished harvesting the crops on one of these rectangles, determine the area of the smallest rectangle that Farmer John can set his new crop harvester to harvest all his crops.

INPUT FORMAT

The first line of input contains four space separated integers x_1, y_1, x_2, and y_2, representing the coordinates of the bottom left and top right corners of the unharvested rectangle of crops. The second line contains four space separated integers x_3, y_3, x_4, and y_4, representing the coordinates of the bottom left and top right corners of the rectangle of crops that Farmer John already harvested. 

OUTPUT FORMAT

Output a single integer representing the area of the smallest rectangle that Farmer John can set his new crop harvester to harvest in order to harvest all of his crops.

SAMPLE INPUT

-3 2 8 5
2 4 9 10
SAMPLE OUTPUT

33
'''

x1, y1, x2, y2 = [int(x) for x in input().split()]

x3, y3, x4, y4 = [int(x) for x in input().split()]

def covered(x, y):
	return 1 if (x3 <= x and x <= x4 and y3 <= y and y <= y4) else 0

corners = covered(x1, y1) + covered(x1, y2) + covered(x2, y1) + covered(x2, y2)
# print(corners)
ans = -1
if (corners <=1):
	ans = (x2-x1)*(y2-y1)
elif (corners == 2):
	intersection = (min(x4, x2) - max(x1, x3)) * (min(y4, y2) - max(y1, y3))
	ans = (x2-x1)*(y2-y1) - intersection
elif (corners == 4):
	ans = 0

print(ans)