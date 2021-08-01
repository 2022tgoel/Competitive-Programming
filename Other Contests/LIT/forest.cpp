#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
const int MXN = 101;
int N;
pair<int,int> pts[MXN];
int o(pii a, pii b, pii c){
	//1 --> ccw, 0 --> collinear, -1 --> cw
	long long x = ((long long)b.f-a.f)*(c.s-b.s) - ((long long)b.s-a.s)*(c.f-b.f);
	if (x > 0) return 1;
	else if (x==0) return 0;
	else return -1;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> pts[i].f >> pts[i].s;
	}
	int ans = 1; //at least 2 points
	for (int i = 0; i < N ;i++){
		for (int j = i+1; j < N ;j++){
			int c = 2;
			for (int k = 0; k < N; k++){
				if (k==i || k==j) continue;
				if (o(pts[i], pts[j], pts[k]) ==0){
					c++;
				}
			}
			ans = max(c, ans);
		}
	}
	cout << ans;
}