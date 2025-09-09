#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int N, D;
int A, B;
vector<int> arr;
vector<long long> pref;

const int MOD = 1e9 + 7;

int sq(long long a) {
    return (a * a) % MOD;
}

bool can_fill(int index, int h, long long v) {
    int lo = index;
    int hi = N;
    while (lo < hi - 1) {
        int mid = (lo + hi) / 2;
        if (arr[mid] < h) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    long long to_fill = (long long)h * (long long)(lo + 1 - index) - (long long)(pref[lo + 1] - pref[index]);
    return to_fill <= v;
}


int search_height(int index, int days, long long vol) {
    int lo = 0;
    int hi = days + 1;
    while (lo < hi - 1) {
        int mid = (lo + hi) / 2;
        int h = arr[index] + mid;
        if (can_fill(index, h, vol)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return arr[index] + lo;
}

int main() {
    cin >> N >> D >> A >> B;

    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    pref.resize(N + 1);
    pref[0] = 0;
    for (int i = 0; i < N + 1; i++)
        pref[i] = pref[i-1] + arr[i-1];

    long long volume = (long long)D * (long long)(A-B);

    int ans = 0;
    for (int i = 0; i < N-A; i++) {
        ans = (ans + sq(arr[i])) % MOD;
    }

    for (int i = N-A; i < N; i++) {
        int height = search_height(i, D, volume);
        volume -= (height - arr[i]);
        ans = (ans + sq(height)) % MOD;
    }
    std::cout << ans << std::endl;
}