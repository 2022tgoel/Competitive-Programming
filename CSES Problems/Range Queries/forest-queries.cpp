/*
  You are given an n×n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).

Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?

Input

The first input line has two integers n and q: the size of the forest and the number of queries.

Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.

Finally, there are q lines describing the queries. Each line has four integers y1, x1, y2, x2 corresponding to the corners of a rectangle.

Output

Print the number of trees inside each rectangle.

Constraints
1≤n≤1000
1≤q≤2⋅105
1≤y1≤y2≤n
1≤x1≤x2≤n
Example

Input:
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2



Output:
3
1
2
*/

#include <iostream>
using namespace std;
const int MAX_N = 1001;
int N, Q, bit[MAX_N][MAX_N];

void update(int r, int c, int v){
    while (c <=N){
        int rt = r;
        while (rt <=N){
            //        cout << rt << c << bit[rt][c];
            bit[rt][c] += v;
            rt += (rt&-rt);
        }
        c += (c&-c);
    }
    //  cout << endl;
}


int query(int r, int c){
    int ans = 0;
    while (c > 0){
        int rt = r;
        while (rt > 0){
            //         cout << rt << c << bit[rt][c];
            ans += bit[rt][c];
            rt -= (rt&-rt);
        }
        c -= (c&-c);
    }
    //  cout << endl;
    return ans;
}

int main(){
    cin >> N >> Q;
//    cout << "here" << N << Q << endl;
    for(int r = 1; r <= N; r++){
        string s;
        cin >> s;
        //    cout << "hi" << endl;
        for(int c = 1; c <=N ; c++){
            update(r, c, (s[c-1] == '*'));
        }
    }
    for(int i = 0 ;i < Q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (query(r2, c2) + query(r1-1, c1-1) - query(r2, c1-1) - query(r1-1, c2)) << endl;
    }
}