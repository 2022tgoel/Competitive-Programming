/*
Picowso paints in a very particular way. She starts with an N×N blank canvas, represented by an N×N grid of zeros, where a zero indicates an empty cell of the canvas. She then draws N2 rectangles on the canvas, one in each of N2 colors (conveniently numbered 1…N2). For example, she might start by painting a rectangle in color 2, giving this intermediate canvas:

2 2 2 0 
2 2 2 0 
2 2 2 0 
0 0 0 0
She might then paint a rectangle in color 7:

2 2 2 0 
2 7 7 7 
2 7 7 7 
0 0 0 0
And then she might paint a small rectangle in color 3:

2 2 3 0 
2 7 3 7 
2 7 7 7 
0 0 0 0
Each rectangle has sides parallel to the edges of the canvas, and a rectangle could be as large as the entire canvas or as small as a single cell. Each color from 1…N2 is used exactly once, although later colors might completely cover up some of the earlier colors.

Given the final state of the canvas, please count how many of the N2 colors could have possibly been the first to be painted.

INPUT FORMAT (file art.in):
The first line of input contains N, the size of the canvas (1≤N≤1000). The next N lines describe the final picture of the canvas, each containing N integers that are in the range 0…N2. The input is guaranteed to have been drawn as described above, by painting successive rectangles in different colors.
OUTPUT FORMAT (file art.out):
Please output a count of the number of colors that could have been drawn first.
SAMPLE INPUT:
4
2 2 3 0
2 7 3 7
2 7 7 7
0 0 0 0
SAMPLE OUTPUT:
14
In this example, color 2 could have been the first to be painted. Color 3 clearly had to have been painted after color 7, and color 7 clearly had to have been painted after color 2. Since we don't see the other colors, we deduce that they also could have been painted first.

Problem credits: Brian Dean
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 1000+10;
int N;
int grid[MXN][MXN], bit[MXN][MXN];
int t[MXN*MXN], b[MXN*MXN], l[MXN*MXN], r[MXN*MXN];
bool used[MXN*MXN];

void upd(int row, int col, int delta){ 
	while (row <=N){
		int a = col;
		while (a<=N){
			bit[row][a] +=delta;
			//cout << row << ' ' << a << endl;
			a+=(a&-a);
		}
		row+=(row&-row);
	}
}

int qry(int row, int col){
	int ans = 0;
	while (row> 0){
		int a =col;
		while (a > 0){
			ans+=bit[row][a];
			a-=(a&-a);
		}
		row-=(row&-row);
	}
	return ans;
}

int main(){
	ifstream cin("art.in");
	ofstream cout("art.out");
	cin >> N;
	for (int i = 1; i<=N*N; i++) {
		t[i] = N+1;
		l[i] = N+1;
	}
	for (int i = 1; i<=N; i++){ //row
		for (int j=1; j<=N; j++){ //col
			int x;
			cin >> x;
			l[x] = min(l[x], j);
			r[x] = max(r[x], j);
			t[x] = min(t[x], i);
			b[x] = max(b[x], i);
			grid[i][j] = x;
		}
	}
	//cout << "here" << endl;
	int never= 0;
	for (int x = 1; x <=N*N; x++){
		if (r[x] == 0) {
			never++;
			//never occurred
			continue;
		}
		upd(t[x], l[x], 1);
		upd(t[x], r[x]+1, -1);
		upd(b[x]+1, l[x], -1);
		upd(b[x]+1, r[x]+1, 1); 
	}
	if (never == N*N-1){
		cout << N*N-1;
		return 0;
	}
	//cout << "here" << endl;
	for (int i =1; i<=N; i++){
		for (int j = 1; j <=N; j++){
			int x = qry(i, j);
			if (x> 1) used[grid[i][j]] = true;
		}
	}
	int ans = 0;
	for (int i =1; i<=N*N; i++){
		if (!used[i]) ans++;
	}
	cout << ans;
}