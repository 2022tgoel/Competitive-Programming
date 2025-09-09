#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

typedef long long ll;

using namespace std;

int T;

void solve() {
    int N; cin >> N;
    map<ll, set<pair<ll, int> > > jobs;

    for (int i = 0; i < N; i++) {
        ll s, t; cin >> s >> t;
        jobs[s + t].insert(make_pair(t, i));
    }

    set< pair<ll, int> > used_jobs;
    ll sum = 0;

    for (auto& [time, list] : jobs) {
        for (auto& job : list) {
            if (job.first + sum <= time) { // just add it
                used_jobs.insert(job);
                sum += job.first;
            } else if (used_jobs.size()) {
                auto last_job = *(--used_jobs.end());
                if (job.first < last_job.first) {
                    used_jobs.erase(last_job);
                    used_jobs.insert(job);
                    sum -= last_job.first;
                    sum += job.first;
                }
            }
        }
    }

    cout << used_jobs.size() << endl;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
}