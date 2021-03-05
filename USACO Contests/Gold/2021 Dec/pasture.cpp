#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
const int MXN = 210;
const int MX = 2e9;
int N;
pii p[MXN];

int solve(){
	sort(p, p+N);
	int ans = 0;
	for (int l = 0; l < N; l++){ //left point
		set<int> y;
		for (int r = l; r < N; r++) { //right point
			y.insert(p[r].s);
			int width = p[r].f - p[l].f;
			int lo = max(p[r].s, p[l].s) - width;
			int hi = min(p[r].s, p[l].s);
			if (lo > hi) break;
			int cur = lo;
			ans++;
			while (cur < hi){
				auto bp = y.lower_bound(cur);
				auto tp = --y.upper_bound(cur+width);
				int leave_bottom = (*(++bp) <=hi ? *(++bp) : MX);
				int enter_top = ((++tp) == y.end() ? MX : *(++tp)-width);
				cur = min(leave_bottom, enter_top);
				if (cur !=MX) ans++;
			}
		}
	}
}


int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].f >> p[i].s;
	}
	int ans = 0;
	ans+=solve();
	//for (int i = 0; i < N; i++) swap(p[i].f, p[i].s);
	//ans+=solve();
	cout << ans;
}