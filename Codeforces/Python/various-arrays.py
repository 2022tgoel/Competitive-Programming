# https://codeforces.com/problemset/problem/1783/D

maxval = 300 * 300 * 2 + 100
shift = 300 * 300
MOD = 998244353

n = int(input())
arr = [int(x) for x in input().split(" ")]

dp = [[0] * maxval for i in range(n-1)]

dp[0][arr[1] + shift] = 1

for i in range(0, n-2):
    val = arr[i+2]
    for j in range(maxval):
        if (dp[i][j] != 0):
            if (j == shift):
                dp[i+1][val + shift] += dp[i][j]
            else:
                dp[i+1][val + (j - shift) + shift] = (dp[i+1][val+j] + dp[i][j]) % MOD
                dp[i+1][val - (j - shift) + shift ] = (dp[i+1][val - (j - shift) + shift ] + dp[i][j]) % MOD
    # print(sum(dp[i+1]), dp[i+1][shift:shift+2])

print(sum(dp[n-2]))