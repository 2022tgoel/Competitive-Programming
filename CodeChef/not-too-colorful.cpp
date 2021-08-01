#include <bits/stdc++.h>
using namespace std;
int T;
char grid[600][600];
int main(){
	cin >> T;
	for (int k = 0;k < T; k++){
		int N, M, R, G, B; 
		vector<pair<int, char>> c(3); 
		cin >> N >> M >>R >> G >>B;
		for (int i = 0 ; i < N; i++){
			for (int j = 0; j < M; j++) grid[i][j] = 'E';
		}
		c[0] = {R,'R'};
		c[1] = {G, 'G'};
		c[2] = {B, 'B'};
		sort(c.begin(), c.end());
		int c0 = 0; int c1 = 0;
		for (int i = 0; i < N ; i++){
			for (int j = 0; j < M; j++){
				if ((i+j)&1 && c0 < c[0].first){
					//0
					grid[i][j] = c[0].second;
					c0++;
				}
				if (!((i+j)&1) && c1 < c[1].first){
					//1
					grid[i][j] = c[1].second;
					c1++;
				}

			}
		}
		for (int i = 0; i < N*M; i++){
			if (grid[i/M][i%M] == 'E') {
				grid[i/M][i%M] = c[2].second;
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M ;j++){
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
}