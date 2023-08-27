// https://codeforces.com/problemset/problem/1749/E

#include <bits/stdc++.h>
#define Node pair<int, int>
using namespace std;

#define MAX 5e5

bool is_valid(int r, int c, set<Node>& cacti) {
    // no cacti in neighboring area 
    bool valid = true;
    valid &= (cacti.count(make_pair(r-1, c)) == 0);
    valid &= (cacti.count(make_pair(r+1, c)) == 0);
    valid &= (cacti.count(make_pair(r, c-1)) == 0);
    valid &= (cacti.count(make_pair(r, c+1)) == 0);
    return valid;
}

bool in_bounds(int r, int c, int n, int m) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

void solve(){
    int n,m; cin >> n >> m;
    set<Node> cacti({});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#')
                cacti.insert(make_pair(i, j));
        }
    }
    set<pair<int, Node>> q;
    map<Node, int> dist;
    map<Node, Node> prev;
    set<Node> visited;
    for (int i = 0; i < n; i++) {
        if (cacti.count(make_pair(i, 0)) > 0) {
            Node n{i, 0};
            q.insert(make_pair(0, n));
            dist[n] = 0;
        } else if (is_valid(i, 0, cacti)) {
            Node n{i, 0};
            q.insert(make_pair(1, n));
            dist[n] = 1;
        }
    }
    int dr[4]{1, -1, 1, -1};
    int dc[4]{-1, -1, 1, 1};
    pair<int, Node> ans = make_pair(MAX, Node{-1, -1});
    while (q.size()) {
        Node cur = (*q.begin()).second;
        int d = dist[cur];
        q.erase(make_pair(d, cur));
        visited.insert(cur);
        // cout << "visit" << cur.first << ' ' << cur.second << " dist: " << d << endl;
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i]; int nc = cur.second + dc[i];
            Node next{nr, nc};
            // cout << "check" << nr << ' ' << nc << endl;
            if (!in_bounds(nr, nc, n, m)) continue;
            if (visited.count(next) > 0) continue;
            bool is_cacti = (cacti.count(make_pair(nr, nc)) > 0);
            if (!is_cacti && !is_valid(nr, nc, cacti)) continue;
            int cost = 1;
            if (is_cacti) cost = 0;
            int newd = MAX;
            // clear the q
            if (dist.count(next) > 0) {
                newd = dist[next];
            }
            if (d + cost < newd) {
                newd = d + cost;
                q.insert(make_pair(newd, next));
                dist[next] = newd;
                prev[next] = cur;
                if (nc == m - 1 && ans.first > newd) {
                    ans = make_pair(newd, next);
                }
            }
            
        }
    }
    if (ans.first == MAX) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    set<Node> placed;
    Node cur = ans.second;
    while (prev.count(cur)) {
        placed.insert(cur);
        // std::cout << cur.first << ' ' << cur.second << endl;
        cur = prev[cur];
    }
    placed.insert(cur);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Node n{i, j};
            if (placed.count(n) || cacti.count(n)) 
                std::cout << '#';
            else 
                std::cout << ".";
        }
        std::cout << endl;
    }
    // std::cout << ans.first << endl;// temporary
}


int main () {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}