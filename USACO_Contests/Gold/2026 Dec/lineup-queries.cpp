#include <iostream>

using namespace std;


int Q;

long long solve_1(long long c, long long t){
    // case 1:
    if (t >= c && t < 2 * c) {
        return c;
    }
    // case 2:
    if (t >= 2 * c && t < 3 * c){
        return c - 1 - (t - 2 * c);
    }

    // case 3:
    long long x = 3 * c;

    while (true) {
        long long y = x + x / 2 + 1;
        if (y > t) break;
        x = y;
    }

    long long additional_time = t - x;
    return x / 2 - additional_time;
}

long long solve_2(long long x, long long t){
    // what cow is as position x at time t
    // case 1: [t, 2t)
    if (x > t / 2) {
        return x;
    }
    // case 2:
    if ((2 * t - x - 1) % 3 == 0) {
        long long y = (2 * t - x - 1) / 3;
        return t - y;
    }

    // case 3:
    long long y = (t - 2 * x) / 3;
    long long crit_time = t - y;

    while (crit_time % 3 != 0 && crit_time >= 3) {
        crit_time = (2 * (crit_time - 1) + 1) / 3;
    }


    return crit_time / 3;
}

int main(){
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int typ;
        long long c, t;
        cin >> typ >> c >> t;
        if(typ == 1){
            cout << solve_1(c, t) << endl;
        }
        if(typ == 2){
            cout << solve_2(c, t) << endl;
        }
    }
}

// 1 0 9
// 1 1 9
// 1 2 9
// 1 3 9

// 1 4 9
// 1 5 9

// 1 6 9
// 1 7 9
// 1 8 9

// 1 9 9
// 2 0 9
// 2 1 9

// 2 2 9

// 2 0 4 1 3 5 6 7 8 9

// 2 4 9

// 2 5 9
// 2 6 9
// 2 7 9
// 2 8 9
// 2 9 9
// 1 0 1000000000000000000
// 2 0 10000000000000000001