/*
The famous global economic crisis is approaching rapidly, so the states of Berman, Berance and Bertaly formed an alliance and allowed the residents of all member states to freely pass through the territory of any of them. In addition, it was decided that a road between the states should be built to guarantee so that one could any point of any country can be reached from any point of any other State.

Since roads are always expensive, the governments of the states of the newly formed alliance asked you to help them assess the costs. To do this, you have been issued a map that can be represented as a rectangle table consisting of n rows and m columns. Any cell of the map either belongs to one of three states, or is an area where it is allowed to build a road, or is an area where the construction of the road is not allowed. A cell is called passable, if it belongs to one of the states, or the road was built in this cell. From any passable cells you can move up, down, right and left, if the cell that corresponds to the movement exists and is passable.

Your task is to construct a road inside a minimum number of cells, so that it would be possible to get from any cell of any state to any cell of any other state using only passable cells.

It is guaranteed that initially it is possible to reach any cell of any state from any cell of this state, moving only along its cells. It is also guaranteed that for any state there is at least one cell that belongs to it.

Input
The first line of the input contains the dimensions of the map n and m (1 ≤ n, m ≤ 1000) — the number of rows and columns respectively.

Each of the next n lines contain m characters, describing the rows of the map. Digits from 1 to 3 represent the accessory to the corresponding state. The character '.' corresponds to the cell where it is allowed to build a road and the character '#' means no construction is allowed in this cell.

Output
Print a single integer — the minimum number of cells you need to build a road inside in order to connect all the cells of all states. If such a goal is unachievable, print -1
*/

#include <iostream>
#include <deque>
#include <fstream>
#include <utility>
#include <vector>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
int n, m, grid[1010][1010];
int dist[4][1010][1010];
void BFS (int src){
	deque<pii> q;
	for (int i = 0; i < n; i++){
		for(int j = 0; j <m; j++) {
			if (grid[i][j] == src)  {
				q.push_back(make_pair(i, j));
				dist[src][i][j] = 0;
			}
			else{
				dist[src][i][j] = -1;
			}
		}
	}
	while (!q.empty()){
		pii cur = q.front();
		q.pop_front();
		int x = cur.f;
		int y = cur.s;
		vector<pii> trans;
		if (x-1 >= 0) {
			trans.push_back(make_pair(x-1, y));
		}
		if (x+1<n) {
			trans.push_back(make_pair(x+1, y));
		}
		if (y-1 >= 0) {
			trans.push_back(make_pair(x, y-1));
		}
		if (y+1 <m) {
			trans.push_back(make_pair(x, y+1));
		}
		for (pii p : trans){
			if (dist[src][p.f][p.s] >= 0 || grid[p.f][p.s] == -1) continue;
			else if (grid[p.f][p.s] == 0) {
				q.push_back(p);
				dist[src][p.f][p.s] = dist[src][x][y] + 1;
			}
			else {
				q.push_front(p); 
				dist[src][p.f][p.s] = dist[src][x][y];
			}
		}
	}
}

int main(){
	ifstream cin ("three-state.in");
	ofstream cout ("three-state.out");
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char c;
			cin >> c;
			int x = 0;
			if (c == '#') {
				x = -1;
			}  
			else if (c!='.'){
				x = c - '0';
			}
			else {
				x = 0;
			}
			grid[i][j]  =x;
		}
	}
	BFS(1);
	BFS(2);
	BFS(3);
	int ans = 1e8;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (dist[1][i][j] == -1 || dist[2][i][j] == -1 ||  dist[3][i][j] == -1) continue;
			int d = dist[1][i][j] + dist[2][i][j] + dist[3][i][j];
			if (grid[i][j] == 0) d-=2;
			ans = min(ans, d);
			//cout << i << j << d <<dist[1][i][j] <<dist[2][i][j] << dist[3][i][j] << endl;
		}
	}
	if (ans < 1e8) cout << ans;
	else cout << -1;
}