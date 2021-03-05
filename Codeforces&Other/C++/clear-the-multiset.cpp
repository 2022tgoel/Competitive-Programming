/*
You have a multiset containing several integers. Initially, it contains a1 elements equal to 1, a2 elements equal to 2, ..., an elements equal to n.

You may apply two types of operations:

choose two integers l and r (l≤r), then remove one occurrence of l, one occurrence of l+1, ..., one occurrence of r from the multiset. This operation can be applied only if each number from l to r occurs at least once in the multiset;
choose two integers i and x (x≥1), then remove x occurrences of i from the multiset. This operation can be applied only if the multiset contains at least x occurrences of i.
What is the minimum number of operations required to delete all elements from the multiset?

Input
The first line contains one integer n (1≤n≤5000).

The second line contains n integers a1, a2, ..., an (0≤ai≤109).

Output
Print one integer — the minimum number of operations required to delete all elements from the multiset.
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 5010;
int N, arr[MXN], dp[MXN];

int solve(int l, int r, int x){
	if (l>r) return 0;
	int mn = arr[l];
	int mind = l;
	for (int i = l+1; i <=r; i++){
		if (arr[i] < mn){
			mn = arr[i]; mind = i;
		}
	}
	int apply = mn -x; //how many times the range is applied 
	int ans = min(r-l+1, apply + solve(l, mind-1, mn) + solve(mind+1, r, mn));
	return ans;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << solve(0, N-1, 0);
	/*
	dp[0] = 1;
	for (int i = 1; i < N; i++){
		dp[i] = dp[i-1]+1;
		int mn = arr[i];
		int cmin= 1;
		for (int j = i-1; j>=0; j--){
			if (arr[j] == 0) break;
			if (arr[j] < mn){
				mn = arr[j];
				cmin =1;
			}
			else if (arr[j] == mn){
				cmin++;
			}
			dp[i] = min(dp[i], (j-1>=0 ? dp[j-1] : 0) + (i-j+1-cmin) + mn);
		}
	}
	cout << dp[N-1];
	*/
}