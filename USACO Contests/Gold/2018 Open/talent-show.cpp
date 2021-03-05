#include <bits/stdc++.h>
using namespace std;
int N, W;
int cow[260][2];
long long dp[1010];
const int inf = -1e8;
bool solve(int x){
	for(int i = 0; i <=W; i++){
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int i = 0; i < N;i++){
		long long c = 1000*(long long)cow[i][1] - x*(long long)cow[i][0];
		for(int j = W; j>=0; j--){
			int weight = j+cow[i][0];
			if (weight > W) weight = W;
			dp[weight] = max(dp[weight], dp[j] + c);
		}
	}
	return (dp[W]>=0);
}

int main(){
	ifstream cin("talent.in");
	ofstream cout("talent.out");
	cin >> N >> W;
	for (int i = 0; i < N; i++){
		cin >> cow[i][0] >> cow[i][1];
	}
	int low = 0;
	int high = 1000*1000+1;
	while(high-1>low){ //[low, high)
		int mid = (low+high)/2;
		bool works = solve(mid);
		if (works){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	cout << low;
}