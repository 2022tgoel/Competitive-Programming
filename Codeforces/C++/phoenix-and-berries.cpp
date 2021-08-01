#include <bits/stdc++.h>
using namespace std;
int n, k, berr[510][2];
int main(){
	cin >> n >> k;
	int tot = 0;
	long long r1 = 0;
	long long r2 = 0;
	for (int i = 0; i < n; i++){
		cin >> berr[i][0] >> berr[i][1];
		r1+=berr[i][0];
		r2+=berr[i][1];
	}
	long long ans = r1/k + r2/k;
	int x = r1%k;
	int y = r2%k;
	if (x + y < k) cout << ans;
	else {
		for (int i = 0; i < n; i++){
			if (berr[i][0] + berr[i][1]  >= k && y>= k - berr[i][0] && x >= k - berr[i][1]){
				ans+=1;
				break;
			}
		}
		cout << (ans);
	}
	
}