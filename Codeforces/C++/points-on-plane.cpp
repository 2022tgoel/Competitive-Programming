#include <bits/stdc++.h>
#define pii pair<int, int> 
#define f first
#define s second
using namespace std;
const int K = 1000;
int N;
vector<pii> pts[K+1];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> N;
	for (int i= 0; i < N;i++){
		int a, b; cin >> a >> b;
		pts[b/K].push_back({a,i+1});
	}
	for (int i = 0; i <= K;i++){
		if (i&1){
			sort(pts[i].begin(), pts[i].end(), greater<pair<int, int>>());
		}
		else sort(pts[i].begin(), pts[i].end());
		for (pii p : pts[i]){
			cout << p.s << ' ';
		}
	}
}