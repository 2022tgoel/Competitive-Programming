#include <iostream>
using namespace std;

int K, N, L;

const int MXN = 1e6 + 10;

const long long MOD = 1e9 + 7;

bool seq[MXN];

int choose[MXN];

long long modPow(long long a, long long e, long long m) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return res;
}

long long modInversePrime(long long a, long long m) {
    return modPow(a, m - 2, m); // works only if m is prime
}

int main() {
    cin >> K >> N >> L;

    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == 'M') {
            seq[i] = true;
        }
        else {
            seq[i] = false;
        }
    }

    choose[K] = 1;

    for (int i = K+1; i < N; i++) {
        long long t1 = ((long long)choose[i-1] * (long long)i) % MOD;
        choose[i] = (t1 * modInversePrime(i-K, MOD) % MOD);
    }

    int ans = 1;

    int num_o = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (seq[i]) {
            ans = ((long long) ans * (long long) choose[num_o]) % MOD;
            num_o -= K;
        } else {
            num_o++;
        }
    }
    cout << modPow(ans, L, MOD);

}