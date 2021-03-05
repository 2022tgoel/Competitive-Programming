/*
  Given an array of n integers, your task is to process q queries of the following types:
update the value at position k to u
what is the minimum value in range [a,b]?
Input

The first input line has two integers n and q: the number of values and queries.

The second line has n integers x1,x2,…,xn: the array values.

Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output

Print the result of each query of type 2.

Constraints
1≤n,q≤2⋅105
1≤xi,u≤109
1≤k≤n
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 2 3
2 1 4

Output:
2
1
3

*/

#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N= 2e5;
int N, Q, val[MAX_N], tree[4*MAX_N];
void build(int ind, int l, int r) {
    if(l==r){
        tree[ind] = val[l];
        return;
    }
    build (ind <<1, l, (l+r)/2);
    build ((ind<<1)+1, (l+r)/2 +1, r);
    tree[ind] = tree[ind << 1] ^ tree[(ind << 1)+1];
}
void update(int ind, int l, int r, int k, int u){
    if (k < l || k > r) return;
    if(l==r) {
        tree[ind] = u;
        return;
    }
    update(ind << 1, l, (l+r)/2, k, u);
    update((ind << 1)+1, (l+r)/2 + 1, r, k, u);
    tree[ind] = tree[ind << 1] ^ tree[(ind << 1)+1];
}
int query(int ind, int l, int r, int a, int b){
    if(b<l || a>r) return 0;
    if(a<=l && r<=b) { //cout << tree[ind];
        return tree[ind]; }
    return query(ind << 1, l, (l+r)/2, a, b) ^ query((ind <<1)+1, (l+r)/2+1, r, a, b);
}
int main(){
    memset(tree, 0, sizeof(tree));
    cin >> N >> Q;
    for(int i =0 ;i < N; i++) cin >> val[i];
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        int a, b;
        cin>> a >> b;
        // if (cmd == 1) update(1, 0, N-1, a-1, b);
        //if (cmd == 2)
        cout << query(1, 0, N-1, a-1, b-1) << endl;
    }
}