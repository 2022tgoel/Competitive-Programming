#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);
    int n; cin >> n;
    double p[n];
    for (int i = 0; i < n; i++) {
        int pt; cin >> pt;
        p[i] = pt * 0.000001;
    }
    // left and right pointers
    int l = 0, r = 0;
    // product of 1-p_i and sum of p_i/(1-p_i) within current interval
    double prod = 1, sum = 0;
    // answer
    double mxp = -1;
    while (l < n) {
        // advance right pointer as long as condition is satisfied
        while (r < n && sum < 1) {
            // update product and sum
            prod *= (1 - p[r]);
            sum += p[r] / (1 - p[r]);
            r++;
        }
        // expression for probability is prod * sum
        mxp = max(mxp, prod * sum);
        // advance left pointer by removing from prod and sum
        prod /= (1 - p[l]);
        sum -= p[l] / (1 - p[l]);
        l++;
    }
    cout << (int) (1000000 * mxp) << endl;
    return 0;
}