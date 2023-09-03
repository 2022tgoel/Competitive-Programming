// https://codeforces.com/problemset/problem/1396/C
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+10;
int n;
int r1, r2, r3;
int d;
int v[MAXN];
int dp[MAXN][3];
int costNoMove(int m) {
    return m*r1 + r3;
}

int costMove(int m) {
    return min(r2 + r1, (m+2) * r1);
}

int best(int i) {
    min(min(dp[i][0], dp[i][1]), dp[i][2]);
}

int b[MAXN];


// 3 states
// 0- didn't move
// 1- moved to the left
// 2- moved to the right
#undef int
int main() {
#define int long long
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    dp[0][0] = costNoMove(v[0]);
    dp[0][1] = costMove(v[0]) + 2*d;
    dp[0][2] = costMove(v[0]) + 2*d;
    b[0] = min(costNoMove(v[0]), costMove(v[0]));
    for (int i = 1; i < n; i++) {
        int cnm = costNoMove(v[i]);
        int cm = costMove(v[i]);
        b[i] = min(cnm, cm);
        dp[i][0] = cnm + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + d;
        dp[i][1] = min(min(dp[i-1][0] + cm, dp[i-1][1] + cm), dp[i-1][2] + cm - 2*d) + 2*d + d;
        dp[i][2] = min(min(dp[i-1][0] + cm, dp[i-1][1] + cm), dp[i-1][2] + cm) + 2*d + d;
        // cout << best(i-1) << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    }
    int ans = min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    int x = 0;
    // special case for the end
    for (int i = n-1; i >= 0; i--) {
        x+= i < n-1 ? b[i] : costNoMove(v[n-1]);
        int bestPrev = i > 0 ? min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + d : 0;
        ans = min(ans, (n-1 - i)*2*d + x + bestPrev);
        // cout << (n-1 - i)*2*d << ' ' << x<< ' ' << bestPrev << endl;
    }

    cout << ans << endl;
}