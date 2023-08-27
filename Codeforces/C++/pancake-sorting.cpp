// https://codeforces.com/problemset/problem/1675/G#

#include <bits/stdc++.h>

using namespace std;

#define MAXM 251
#define MAXN 251

#define MAXCOST 251 * 251

int dp[MAXN][MAXM][MAXM];
int arr[MAXN];
int pref[MAXN];
int main() {
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
        pref[i] = arr[i];
        if (i > 0) pref[i] += pref[i-1];
    }
    // for (int i = 0; i < n; i++) cout << pref[i] << ' ';
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= m; j++) 
            for (int k = 0; k <=m; k++)
                dp[i][j][k] = MAXCOST;
    
    for (int j = 0; j <=m; j++) {
        dp[0][j][j] = abs(pref[0] - j);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j <= m; j++) {
            int best[MAXM];
            for (int l = m; l >=0; l--) {
                best[l] = dp[i][j][l];
                if (l < m) best[l] = min(best[l], best[l+1]);
            }
            for (int p = 0; p <= j; p++) {
                if (j + p > m) continue;
                dp[i+1][j+p][p] = min(dp[i+1][j+p][p], best[p] + abs(j+p - pref[i+1]));
            }
        }
    }
    int ans = MAXCOST;
    for (int i = 0; i <= m; i++) ans = min(ans, dp[n-1][m][i]);
    cout << ans << endl;
}