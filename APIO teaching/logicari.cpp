#include <bits/stdc++.h>
#define MAXN 100010
#define INF 1000000
using namespace std;
int N;
vector<int> adj[MAXN];
int dp[MAXN][2][2];
bool leaf[MAXN];
int par[MAXN];
bool v[MAXN];

void dfs(int cur){
    v[cur] = true;
    bool l = true;
    for (int nxt : adj[cur]) {
        if (!v[nxt]) {
            par[nxt] = cur;
            dfs(nxt);
            l = false;
        }
    }
    leaf[cur] = l;
}

int solve(int node, int blue, int parblue){
    if (dp[node][blue][parblue] != -1) return dp[node][blue][parblue];

    dp[node][blue][parblue] = INF;

    if (leaf[node]) {
        if (parblue) dp[node][blue][parblue] = blue;
        return dp[node][blue][parblue];
    }

    int s = 0;
    for (int child : adj[node]){
        if (child == par[node]) continue;
        s += solve(child, 0, blue);
    }
    
    if (!parblue){ // need to make one the the children blue
        for (int child : adj[node]){
            if (child == par[node]) continue;
            int val = s - solve(child, 0, blue) + solve(child, 1, blue); 
            dp[node][blue][parblue] = min(dp[node][blue][parblue], val);
        }
    }
    else dp[node][blue][parblue] = min(dp[node][blue][parblue], s);
    return dp[node][blue][parblue];
}

int main(){
    cin >> N;
    for (int i = 1; i < N; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(v, 0, MAXN);
    dfs(1);
    par[1] = -1;

    memset(dp, -1, 4*MAXN*4);
    
    int sol1 = solve(1, 1, 0);
    int sol2 = solve(1, 0, 0);
    cout << min(sol1, sol2) << endl;
}