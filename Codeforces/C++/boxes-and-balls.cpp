#include <bits/stdc++.h>
using namespace std;
int v[2000];
int balls[2000];

int solve(int i, int j, int k) {
    // first i balls
    // confined to j space (0..j)
    // using at most k moves
    if (i > j + 1) {
        return 0;
    }
    if (i == 1) {
        int pos = balls[0];
        if (k == 0) return pos <= j;
        return (int) (pos + k <= j) + (int) (pos - k >= 0); 
    }
    int ans = 0;
    int pos = balls[i-1]; // location of this ball
    for (int x = max(0, pos - k); x<=min(j, pos + k); x++) { // all possible new locations
        int moves = abs(x - pos);
        ans += solve(i-1, x-1, k - moves);
        if (i == 5) {
            cout << ans << endl;
        }
    }
    return ans;
}

int main(){
    int n, k; cin >> n >> k;
    int nb = 0; // # of balls
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]) {
            balls[nb++] = i;
        }
    }
    cout << solve(nb, n-1, k) << endl;
}