#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <set>

using namespace std;

const int MAXN = 2e5+10;

int N, M;
int par[MAXN];
vector<int> lbl[MAXN];
int sz[MAXN];

int deg[MAXN];
bool not_in_cycle[MAXN];

int find(int x, set<int> visited) {
    if (visited.count(x)) {
        return 0;
    }
    if (lbl[x].size()) {
        return x;
    }
    visited.insert(x);
    int y = find(par[x], visited);
    if (y) {
        par[x] = y;
    }
    return y;
}

void join(int y, int x) {
    par[x] = y;
    sz[y] += sz[x];
}

int get_cur_lbl(int x) {
    return lbl[x][lbl[x].size() - 1];
}

void get_cycle_nodes() {
    deque<int> v;
    for (int i = 1; i <= N; i++) {
        // Use indegree trimming: nodes with indegree 0 cannot be in any cycle
        if (deg[i] == 0) {
            v.push_back(i);
        }
    }
    while (v.size()) {
        int x = v.front();
        v.pop_front();
        not_in_cycle[x] = true;
        int nxt = par[x];
        // Remove edge x -> nxt, decreasing nxt's indegree
        deg[nxt]--;
        if (deg[nxt] == 0) {
            v.push_back(nxt);
        }
    }
}

pair<int, char> events[MAXN];

int ans[MAXN][3];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        par[i] = x;
        // Track indegree only (incoming edges count)
        deg[x]++;
    }
    get_cycle_nodes();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x; char c;
        cin >> x >> c;
        if (c == 'C') {
            lbl[x].push_back(0);
        } else if (c == 'O') {
            lbl[x].push_back(1);
        } else if (c == 'W') {
            lbl[x].push_back(2);
        }
        events[i] = make_pair(x, c);
    }

    array<int, 3> num = {0, 0, 0};

    for(int i = 1; i <= N; i++) {
        int y = find(i, set<int>());
        if (y) {
            int l = get_cur_lbl(y);
            sz[y]++;
            num[l]++;
        }
    }

    for (int i = M-1; i >= 0; i--) {
        ans[i][0] = num[0];
        ans[i][1] = num[1];
        ans[i][2] = num[2];
        int x = events[i].first;
        int l = lbl[x].back();
        lbl[x].pop_back();
        num[l] -= sz[x];
        if (lbl[x].size()) {
            num[get_cur_lbl(x)] += sz[x];
        } else {
            // merge into parent
            int new_par = find(par[x], set<int>());
            if (new_par) {
                num[get_cur_lbl(new_par)] += sz[x];
                join(new_par, x);
            }
        }

    }

    for (int i = 0; i < M; i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    }
}