#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const int MXN = 1e5+10;
int N, T;
pair<ll, ll> pts[MXN];
ll best[MXN]; // greatest val 
int dp[MXN];

int max_len(ll x){
	int lo =0; int hi = MXN; //[lo, hi)
	while (lo+1 < hi){
		int mid = (lo+hi)/2;
		if (x <= best[mid]){
			lo = mid; //can get at least this length
		}
		else {
			hi = mid; //impossible
		}
	}
	return lo;
}

int main(){
	ifstream cin("cowjog.in");
	ofstream cout("cowjog.out");
	cin >> N >> T;
	for (int i= 0; i < N; i++){
		int a,b; cin >> a >> b;
		pts[i] = {a, a+(ll)b*T};
	}
	sort(pts, pts+N);
	//longest decreasing subsequence
	int ans = 0;
	for(int i=0; i < N; i++){
		ll x = pts[i].s;
		dp[i] = max_len(x)+1;
		assert(dp[i]<=N);
		ans = max(dp[i], ans);
		best[dp[i]] = x;
	}
	cout << ans;
}