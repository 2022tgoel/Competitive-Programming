#include <iostream>

using namespace std;

const int MAXN = 1e6+10;
const int MOD = 1e9 + 7;

int N, D;

int camper[MAXN];
int coach[MAXN];
int coach_cant[MAXN];
int dp_carry[MAXN];
int dp_include[MAXN]; // number of solutions that include this cow
int dp[MAXN]; // number of solutions, may or may not include this cow

long long modpow(long long x, long long y, long long m) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

long long pow2(long long x) {
    return modpow(2, x, MOD);
}

long long moddiv(long long x, long long y) {
    return (x * modpow(y, MOD - 2, MOD)) % MOD;
}

long long modsub(long long x, long long y) {
    return (x - y + MOD) % MOD;
}

long long modmul(long long x, long long y) {
    return (x * y) % MOD;
}

long long modadd(long long x, long long y) {
    return (x + y) % MOD;
}

int main(){
    cin >> N >> D;
    int ncamper = 0;
    int ncoach = 0;
    for(int i = 0; i < N; i++){
        int p, o; cin >> p >> o;
        if(o == 0){
            camper[ncamper++] = p;
        }
        else{
            coach[ncoach++] = p;
        }
    }
    camper[ncamper] = 1000000111;

    int ind = -1;
    for (int j = 0; j < ncamper; j++) {
        while (coach[ind + 1] + D < camper[j]) {
            ind++;
        }
        coach_cant[j] = ind;
    }


    int le = 0;
    int re = 0;

    for (int j = 0; j < ncoach; j++) {
        // you can have any of the campers from [coach[j], coach[j] + D]
        // you can have subset of coaches that don't actually cover the camper in that range
        // start with the coach which can't get any of the campers in range.

        // how many ways with this coach and any of the ones to the left
        // suppose you have a cow and they cannot attend to it -- multiply by 2
        // a cow goes out of range -- divide by 2
        // everything that couldn't attend to it -- you can't attend to it either.
        long long dpval = j > 0 ? dp_carry[j-1] : 0;

        // you can't help this camper
        while (camper[le] < coach[j]) {
            // the previous coach could help this camper
            if (re - le > 0) {
                if (coach_cant[le] > -1) {
                    int to_sub = modmul(dp[coach_cant[le]], pow2(re - le - 1));
                    dpval = modsub(dpval, to_sub);
                }
            }
            le++;
        }

        re = max(re, le);
        dpval = modadd(dpval, j > 0 ? dp_include[j-1] : 0);

        while (camper[re] <= coach[j] + D) {
            re++;
            dpval = modmul(dpval, 2);
        }
        dp_carry[j] = dpval;

        // just including this cow and none else
        dp_include[j] = modadd(dpval, pow2(re - le));

        dp[j] = modadd(dp_include[j], j > 0 ? dp[j-1] : 0);
        // cout << j << ' ' << dpval << ' ' << dp[j] << endl;
    }

    cout << dp[ncoach - 1] << endl;

}