/*
The ill-fated result of watching too many "do it yourself" engineering videos on the web, Farmer John has accidentally released a self-replicating robot on his farm!
The farm can be represented by an N×N grid (3≤N≤1000) where each grid cell is either empty or filled with rock, and all border squares are filled with rock. Some non-rock cells are designated as possible starting locations for the robot.

Farmer John initially places the robot at one of the possible starting positions. In every hour that follows, all copies of the robot move in one coordinated mass in the same direction, either north, south, east, or west. After every D hours (1≤D≤109), every copy of the robot replicates --- a robot at cell (x,y) that replicates creates new copies in cells (x+1,y), (x−1,y), (x,y+1), and (x,y−1); the original robot remains at (x,y). Over time, multiple robots might come to occupy the same cell.

If moving or replicating would cause any of the robots to move into a rock, then all robots shut down immediately. Note that this implies that the robots must eventually shut down, due to the border of the farm being rock.

Help the cows figure out the number of empty squares that could potentially at some point in time hold a robot.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains two space-separated integers N and D. The next N lines of input each contain N characters. Each character is one of '.', 'S', or '#'. '.' and 'S' both represent empty cells, with 'S' denoting a possible starting position for the robot. '#' denotes a rock.
All characters in the first and last row and first and last column are '#'.

OUTPUT FORMAT (print output to the terminal / stdout):
An integer counting the number of cells that could at some point in time hold a robot.
SAMPLE INPUT:
10 1
##########
#........#
#S.......#
#........#
##########
#S....S..#
##########
##########
##########
##########
SAMPLE OUTPUT:
15
In the following diagrams, x's denote robots.

Locations that could be occupied by robots:

##########
#xxx.....#
#xxxx....#
#xxx.....#
##########
#xx..xxx.#
##########
##########
##########
##########
One possible sequence of events could be as follows:

FJ places the robot at the upper-left-most starting position.
The robot moves one unit to the right.
The robot replicates.
All robots move one unit to the right.
Another replication would cause a copy of the robot to move into a rock, so the process terminates.
##########    ##########    ##########    ##########
#........#    #........#    #.x......#    #..x.....#
#x.......#    #.x......#    #xxx.....#    #.xxx....#
#........#    #........#    #.x......#    #..x.....#
########## -> ########## -> ########## -> ##########
#........#    #........#    #........#    #........#
##########    ##########    ##########    ##########
##########    ##########    ##########    ##########
##########    ##########    ##########    ##########
##########    ##########    ##########    ##########
SAMPLE INPUT:
10 2
##########
#.#......#
#.#......#
#S.......#
#.#......#
#.#......#
##########
##########
##########
##########
SAMPLE OUTPUT:
28
Locations that could be occupied by robots:

##########
#x#.xxx..#
#x#xxxxx.#
#xxxxxxxx#
#x#xxxxx.#
#x#.xxx..#
##########
##########
##########
##########
SAMPLE INPUT:
10 2
##########
#.S#.....#
#..#.....#
#S.......#
#..#.....#
#..#.....#
##########
##########
##########
##########
SAMPLE OUTPUT:
10
Locations that could be occupied by robots:

##########
#xx#.....#
#xx#.....#
#xxx.....#
#xx#.....#
#x.#.....#
##########
##########
##########
##########
SCORING:
Test cases 4-5 satisfy D=109.
Test cases 6-8 satisfy D=1.
Test cases 9-12 satisfy N≤100.
Test cases 13-20 satisfy no additional constraints.
Problem credits: Benjamin Qi
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
int N, D;
int grid[1000][1000], rock[1000][1000];

void rockDist(){
	queue<pii> q;
	bool visited[1000][1000];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 2) {
				q.push(make_pair(i, j));
				rock[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	while (!q.empty()){
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = cur.first+dx[i];
			int ny = cur.second+dy[i];
			if (!visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				rock[nx][ny] = rock[cur.first][cur.second]+1;
			}
		}
	}
}

void 

int main(){
	cin >> N >> D;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			char a;
			cin << a;
			if (a == "#") grid[i][j] = 2;
			else if (a == '.') grid[i][j] = 0;
			else grid[i][j] == 1;
		}
	}
	rockDist();
}