#include <bits/stdc++.h>

#define maxval 300 * 300 * 2 + 100
#define shift 300 * 300
#define MOD 998244353

int arr[300];
int dp[300][maxval];
int main() {
    // std::cout << "here" << std::endl;
    int n; std::cin >> n;
    
    for (int i = 0; i < n ;i++) std::cin >> arr[i];

    dp[0][arr[1] + shift] = 1;

    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        int val = arr[i+2];
        for (int j = 0; j < maxval; j++) {
            if (dp[i][j] != 0) {
                if (j == shift) {
                    dp[i+1][val + shift] += dp[i][j];
                } else {
                    dp[i+1][val + (j - shift) + shift] = (dp[i+1][val+j] + dp[i][j]) % MOD;
                    dp[i+1][val - (j - shift) + shift ] = (dp[i+1][val - (j - shift) + shift ] + dp[i][j]) % MOD;
                }
            }
        }
    }
    for (int j = 0 ; j < maxval; j++) ans = (ans + dp[n-2][j]) % MOD;
    std::cout << ans << std::endl;
}