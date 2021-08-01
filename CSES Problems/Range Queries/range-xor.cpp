/*
  Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?

Input

The first input line has two integers n and q: the number of values and queries.

The second line has n integers x1,x2,…,xn: the array values.

Finally, there are q lines describing the queries. Each line has two integers a and b: what is the xor sum of values in range [a,b]?

Output

Print the result of each query.

Constraints
1≤n,q≤2⋅105
1≤xi≤109
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

Output:
3
0
6
4
*/

#include <iostream>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    int pref[200000];
    cin >> pref[0];
    for(int i = 1; i < N; i++) {
        int x;
        cin >> x;
        pref[i] = pref[i-1]^x;
    }
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        int l = (a > 1) ? pref[a-2] : 0;
        cout << (pref[b-1]^l) << endl;
    }
}