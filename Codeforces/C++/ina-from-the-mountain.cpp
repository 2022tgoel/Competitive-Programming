#include <bits/stdc++.h>
using namespace std;

using namespace std;
const int MAXN = 2e5+10;

long long v[MAXN];

long long solve() {
    int n; cin >> n; int k; cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= k) v[i] -=k; // how many ops you need to do
    }
    long long ans = v[0];
    priority_queue<int, vector<int>, greater<int>> costs;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i-1]) {
            costs.push(v[i] - v[i-1]);
        } else {
            costs.push(k + v[i] - v[i-1]);
        }
        if (v[i] > v[i-1]) {
            int val = costs.top();
            ans += val;
            costs.pop();
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        cout << solve() << endl;
}