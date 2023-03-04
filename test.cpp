#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 500
#define ll long long
#define f first
#define s second
 
typedef pair<int, int> pii;
 
int k, m, n;
vector<pii> grass;
vector<int> nhoj;
priority_queue<ll> tastiness;
 
int main() {
    ifstream cin("2.in");
    cin >> k >> m >> n;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        grass.emplace_back(a, b);
    }
    sort(grass.begin(), grass.end());
 
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        nhoj.emplace_back(a);
    }
    sort(nhoj.begin(), nhoj.end());
 
    int nindex = 0;
    for (int i = 0; i < k; i++) {
        while (nindex < nhoj.size() && nhoj[nindex] < grass[i].f) {
            nindex++;
        }
 
        if (nindex == nhoj.size()) {
            ll temp = 0;
            for (int j = i; j < grass.size(); j++) {
                temp += grass[j].s;
            }
            tastiness.emplace(temp);
            break;
        } else {
            int end_index = i + 1;
            while (grass[end_index].f < nhoj[nindex]) {
                end_index++;
            }
            if (end_index > i + 1) {
                end_index--;
                float length=0;
                if(nindex==0){
                    length=float(10e10);
                }
                else{
                    length=nhoj[nindex]-nhoj[nindex-1];
                }
 
                ll temp = 0;
                for (int j = i; j <= end_index; j++) {
                    temp += grass[j].s;
                }
 
                for(int j=i; j<=end_index; j++){
                    ll sum=0;
                    for(int a=j; a<=end_index; a++){
                        sum+=grass[a].s;
                        if(grass[a].f-grass[j].f>=length/2){
                            break;
                        }
                        tastiness.emplace(sum);
                        tastiness.emplace(temp-sum);
                    }
                }
                i=end_index;
            }
            else{
                tastiness.emplace(grass[i].s);
            }
        }
    }
 
//    while (!tastiness.empty()) {
//        cout << tastiness.top() << endl;
//        tastiness.pop();
//    }
//    cout << endl;
//    while (!tastiness2.empty()) {
//        cout << tastiness2.top() << endl;
//        tastiness2.pop();
//    }
//    cout << endl;
 
    ll ans = 0;
    int num = 0;
    while (!tastiness.empty() && num < n) {
        ans+=tastiness.top();
//        cout<<tastiness.top()<<endl;
        tastiness.pop();
        num++;
    }
 
    cout << ans;
}
