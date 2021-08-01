#include <bits/stdc++.h>
using namespace std;
struct grid {
	int s[9];
	grid () {
		for (int i = 0; i < 9; i++) s[i] = 0;
	}
};
grid g = grid();
int swaps[][2] = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8}, {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}};
unordered_map<int, int> visited;

void print_grid(grid a){
	for (int i = 0; i < 9; i++){
		cout << a.s[i] << ' ';
	}
	cout << endl;
}

int encode(grid a){
	int x =0;
	for (int i = 0; i < 9; i++){
		x = x*10 + a.s[i];
	}
	return x;
}

int BFS(){
	queue<grid> q;
	q.push(g);
	visited[encode(g)] = 1;
	while (!q.empty()){
		grid cur = q.front(); q.pop();
		int done = true;
		for (int i = 0; i < 9; i++){
			if (cur.s[i]!=i+1) done=false;
		}
		if (done == true) return visited[encode(cur)]-1;
		grid next = cur;
		for (int i = 0; i < 12; i++){
			int a = swaps[i][0]; int b = swaps[i][1];
			swap(next.s[a], next.s[b]);
			if (visited[encode(next)] == 0){
				visited[encode(next)] = visited[encode(cur)]+1;
				q.push(next);
			}
			swap(next.s[a], next.s[b]);
		}
	}
}

int main(){
	for (int i = 0; i < 9; i++) cin >> g.s[i];
	visited.reserve(524288);
	visited.max_load_factor(0.25);
	cout << BFS();
}