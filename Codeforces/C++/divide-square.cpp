/*
E. Divide Square
time limit per test2 seconds
memory limit per test384 megabytes
inputstandard input
outputstandard output
There is a square of size 106×106 on the coordinate plane with four points (0,0), (0,106), (106,0), and (106,106) as its vertices.

You are going to draw segments on the plane. All segments are either horizontal or vertical and intersect with at least one side of the square.

Now you are wondering how many pieces this square divides into after drawing all segments. Write a program calculating the number of pieces of the square.

Input
The first line contains two integers n and m (0≤n,m≤105) — the number of horizontal segments and the number of vertical segments.

The next n lines contain descriptions of the horizontal segments. The i-th line contains three integers yi, lxi and rxi (0<yi<106; 0≤lxi<rxi≤106), which means the segment connects (lxi,yi) and (rxi,yi).

The next m lines contain descriptions of the vertical segments. The i-th line contains three integers xi, lyi and ryi (0<xi<106; 0≤lyi<ryi≤106), which means the segment connects (xi,lyi) and (xi,ryi).

It's guaranteed that there are no two segments on the same line, and each segment intersects with at least one of square's sides.

Output
Print the number of pieces the square is divided into after drawing all the segments.
*/

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second
const int MX = 1e6;
int n, m;
vector<pii> ranges[MX+10];
int bit[MX+10];
void upd(int ind, int val){
	while (ind <=MX){
		bit[ind]+=val;
		ind+=(ind&-ind);
	}
}
int qry(int ind){
	int ans = 0;
	while (ind>0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
int main(){
	cin >> n >> m;
	set<vector<int>> points;
	long long ans = 1;
	for (int i = 0; i < n; i++){
		int y, l, r;
		cin >> y >> l >> r;
		if (l == 0 && r == MX) ans++;
		points.insert({l, y, 1});
		points.insert({r+1, y, -1});
	}
	for (int i = 0; i < m; i++){
		int x, l, r;
		cin >> x >> l >> r;
		if (l == 0 && r == MX) ans++;
		ranges[x].push_back(make_pair(l, r));
	}
	for (int i = 0; i < MX; i++){
		if (points.size() > 0){
			vector<int> first = *points.begin();
			//cout << first[0] << ' ' << first[1] << ' ' << first[2] << endl;
			while (first[0] == i){
				upd(first[1], first[2]);
				points.erase(first);
				//cout << "visited: " << first[0] << ' ' << first[1] << ' ' << first[2] << endl;
				if (points.size() == 0) break;
				first = *points.begin();
			}
		}
		for (pii range : ranges[i]){
			ans += (qry(range.s) - qry(range.f-1));
		}
	}
	cout << ans;
}