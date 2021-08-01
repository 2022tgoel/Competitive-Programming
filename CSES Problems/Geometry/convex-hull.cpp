#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
const int MXN = 2e5+10;
pii pts[MXN];
int N;
bool cmp(pii a, pii b){
	return a.f < b.f || (a.f == b.f && a.s < b.s);
}


//colinear also counts
bool ccw(pii a, pii b, pii c){
	return  ((long long)b.f - a.f)*((long long) c.s -b.s)  - ((long long)b.s - a.s)* ((long long) c.f -b.f) >= 0;  
}

bool cw(pii a, pii b, pii c){
	return  ((long long)b.f - a.f)*((long long) c.s -b.s)  - ((long long)b.s - a.s)* ((long long) c.f -b.f) <= 0;  
}
void print(pii a){
	cout << a.f << ' ' << a.s << endl;
}

int main(){
	cin >> N;
	for (int i = 0; i < N;i++) {
		cin >> pts[i].f >> pts[i].s;
	}
	sort(pts, pts+N, &cmp);
	pii p1 = pts[0]; pii p2 = pts[N-1];
	vector<pii> up, down;
	up.push_back(p1); down.push_back(p1);
	for (int i = 1; i <= N-1; i++){ //N-1 is super important!!
		if (cw(p1, pts[i], p2)){
			//cout << "up " << i << endl;
			int l = up.size();
			while (l >=2 && !cw(up[l-2], up[l-1], pts[i])){
				up.pop_back();
				l = up.size();
			}
			up.push_back(pts[i]);
		}
		if (ccw(p1, pts[i], p2)){
			//cout << "down " << i << endl;
			int l = down.size();
			while (l>=2 && !ccw(down[l-2], down[l-1], pts[i])){
				down.pop_back();
				l = down.size();
			}
			down.push_back(pts[i]);
		}
	}
	cout << up.size() + down.size() - 2 << endl;
	for (pii p : up){
		print(p);
	}
	for (int i= 1; i < (int)down.size()-1; i++){
		print(down[i]);
	}
}