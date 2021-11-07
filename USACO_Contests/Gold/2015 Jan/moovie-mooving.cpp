#include <bits/stdc++.h>
using namespace std;
const int MXN = 20;

int N, L;
vector<int> times[MXN];
int dur[MXN];
int dp[2000000];
int count(int num){
	return __builtin_popcount(num);

}

int search(int i, int time){
	//farthest you can get with time limit and moovie - less or equal 
	int lo = 0; int hi = times[i].size();
	while (lo < hi-1){
		int mid = (lo+hi)/2;
		if (times[i][mid] <=time){
			lo = mid;
		}
		else hi = mid;
	}
	if (times[i][lo]<=time) return max(time, times[i][lo] + dur[i]);
	else return time;
}

int main(){
	ifstream cin("movie.in");
	ofstream cout("movie.out");
	cin >> N >> L;
	for (int i= 0; i < N; i++){
		cin >> dur[i];
		int n; cin >> n;
		for (int j = 0; j < n;j++){
			int a; cin >> a; 
			times[i].push_back(a);
		}
	}
	int ans = -1;
	dp[0] = 0; // can't get anywhere with no moovies
	for (int i = 1; i < (1<<N); i++){
		for (int j = 0; j < N; j++){
			if (i&(1<<j)){
				dp[i] = max(dp[i], search(j, dp[i^(1<<j)]));
			}
		}
		if (dp[i] >= L) {
			if (ans ==-1) ans = count(i);
			else ans = min(ans, count(i));
		}
	}
	cout << ans << endl;
}