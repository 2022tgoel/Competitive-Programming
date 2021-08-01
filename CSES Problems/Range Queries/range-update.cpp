/*
  Given an array of n integers, your task is to process q queries of the following types:
increase each value in range [a,b] by u
what is the value at position k?
Input

The first input line has two integers n and q: the number of values and queries.

The second line has n integers x1,x2,…,xn: the array values.

Finally, there are q lines describing the queries. Each line has three integers: either "1 a b u" or "2 k".

Output

Print the result of each query of type 2.

Constraints
1≤n,q≤2⋅105
1≤xi,u≤109
1≤k≤n
1≤a≤b≤n
Example

Input:
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

Output:
5
6
*/

#include <iostream>
using namespace std;
const int MAX_N = 2e5+1;
#define ll long long
ll bit[MAX_N];
int N, Q;
void upd(int i, int v){
    while (i <=N){
        bit[i] += v;
        i+=(i&-i);
    }
    return;
}
ll qry(int i){
    ll ans = 0;
    while (i > 0) {
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}
int main(){
    cin >> N >> Q;
    int preval = 0;
    for(int i = 1; i <= N; i++){
        int val;
        cin >> val;
        upd(i, val-preval);
        preval = val;
    }
    for(int i =0; i < Q; i++) {
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int l, r, val;
            cin >> l >> r >> val;
            upd(l, val);
            upd(r+1, -1*val);
        }
        if (cmd == 2){
            int ind;
            cin >> ind;
            cout << qry(ind) << endl;
        }
    }
}