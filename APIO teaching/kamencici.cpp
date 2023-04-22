#include <bits/stdc++.h>
#define MAXN 360
#define INF 400000

using namespace std;

int N, K;
int arr[MAXN];
int pref[MAXN];
int dp[MAXN][MAXN][MAXN];

int solve(int l, int r, int k){ 
    // min amount of red needed to be taken to force opponent to take k red
    // it is always your turn 
    // inf if impossible 
    // -1 if not computed
    assert(r >= l);
    if (dp[l][r][k]!=-1) return dp[l][r][k];
    else if (k == 0) {
        dp[l][r][k] = 0;
        return 0;
    }
    // if (pref[r] - pref[l-1] == 0) { // all blue 
    //     dp[l][r][k] = (k==0) ? 0 : INF;
    //     return dp[l][r][k];
    // }
    // if (pref[r] - pref[l-1] == r-l+1){ // all red 
    //     dp[l][r][k] = (r-l+1 >= 2*k) ? k : INF;
    //     return dp[l][r][k];
    // }
    else if (r-l+1 < 3){
        if (k > 1) dp[l][r][k] = INF;
        if (k == 1 && (arr[l]||arr[r])) dp[l][r][k] = arr[l]&&arr[r];
        return dp[l][r][k];
    }
    else {
        int leftMove = arr[l] + max(solve(l+2, r, k - arr[l+1]), solve(l+1, r-1, k - arr[r])); // had to take one from the left. 
        int rightMove = arr[r] + max(solve(l+1, r-1, k - arr[l]), solve(l, r-2, k - arr[r-1]));
        dp[l][r][k] = min(leftMove, rightMove);
        return dp[l][r][k];
    }
    // 'cccp'
}

int main(){
     cin >> N >> K;
     for (int i = 1; i <= N; i++){
        char c; cin >> c;
        arr[i] = (c == 'C');
        pref[i] = pref[i-1] + arr[i]; // count number of red balls in range 1..i
     }
     memset(dp, -1, 4*MAXN*MAXN*MAXN);
     int cost = solve(1, N, K);
     if (cost < K) cout << "DA";
     else cout << "NE";
     cout << endl;
}