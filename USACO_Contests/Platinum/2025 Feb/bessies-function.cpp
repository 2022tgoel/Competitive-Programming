#include <iostream>
#include <vector>
#include <array>
using namespace std;

const int MXN = 2e5+10;
const long long LARGE = 1e15;

long long dp[MXN][2];

int f[MXN];
vector<int> f_inv[MXN];
long long c[MXN];
int N;

bool in_cycle[MXN];

void calc(int node) {
    for (int c : f_inv[node]) {
        if (!in_cycle[c]) 
            calc(c);
    }
    for (int c : f_inv[node]) {
        if (!in_cycle[c]) {
            dp[node][0] += dp[c][1];
            dp[node][1] += min(dp[c][0], dp[c][1]);
        }
    }
    dp[node][1] += c[node];
}


int visited[MXN];

vector< vector<int> > cycles;

void get_cycle(int i, int iter) {
    int node = i;
    while (!visited[node]) {
        visited[node] = iter;
        node = f[node];
    }
    if (visited[node] != iter)
        return;
    vector<int> cycle;
    int cycle_node = node;
    cycle.push_back(node);
    while (f[cycle_node] != node) {
        cycle_node = f[cycle_node];
        cycle.push_back(cycle_node);
    }
    cycles.push_back(cycle);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> f[i]; f[i]--;
        f_inv[f[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        if (f[i] == i)
            c[i] = 0;
    }
    long long cost = 0;
    // get all of cycle
    int iter = 0;
    for (int i = 0; i < N; i++) {
        get_cycle(i, ++iter);
    }
    for (auto& cycle : cycles) {
        for (int i : cycle) {
            in_cycle[i] = true;
        }
    }
    // do DP on all of these nodes
    for (auto& cycle : cycles) {
        for (int i : cycle) {
            calc(i);
        }
    }
    
    for (auto& cycle : cycles) {
        vector< array<long long, 4> > dpc;
        array<long long, 4> tmp = {dp[cycle[0]][0], LARGE, LARGE, dp[cycle[0]][1]};
        dpc.push_back(tmp);
        for (int i = 1; i < cycle.size(); i++) {
            auto prev = dpc.back();
            auto [ww, bw, wb, bb] = prev;
            long long cw = dp[cycle[i]][0]; long long cb = dp[cycle[i]][1];
            array<long long, 4> tmp = {wb + cw, bb + cw, min(wb, ww) + cb, min(bb, bw) + cb};
            dpc.push_back(tmp);    
        }
        auto [ww, bw, wb, bb] = dpc.back();
        cost += min(min(bw, wb), bb);
    }
    cout << cost << endl;
}