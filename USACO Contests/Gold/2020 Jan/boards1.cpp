#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int N, P;
const int MXP = 1e5+10;
struct Point {
	int x, y, ind;
	bool type;  
	bool operator<(const Point& other) const{
		if (x < other.x) return true;
		else if (x == other.x) return y < other.y;
		else return false;
	}
};

set<Point> points;
map<int, int> best; //minimum cost-x-y to reach an y
int cost[MXP]; //cost to get to springboard i
int main(){
	ifstream cin ("boards.in");
	ofstream cout ("boards.out");
	cin >> N >> P;
	for (int i = 0; i < P; i++){
		Point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		a.ind = i;
		b.ind = i;
		a.type = 1;
		b.type = 0;
		points.insert(a);
		points.insert(b);
	}
	best[0] = 0; //guarantees a y below or equal
	for (Point cur : points){
		if (cur.type){ //start point
			cost[cur.ind] = (--best.upper_bound(cur.y))->second+cur.x+cur.y;
		}
		else {
			int val = cost[cur.ind] - cur.x - cur.y;
			auto x = best.upper_bound(cur.y);
			if ((--x)->second <=val) continue;
			x++;
			while (x!=best.end() && x->second >= val) { //inferior point
				best.erase(x++);
			}
			best[cur.y] = val;
		}
	}
	cout << best.rbegin()->second + 2*N;
}