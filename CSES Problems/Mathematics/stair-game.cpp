/*
 * There is a staircase consisting of n stairs, numbered 1,2,…,n. Initially, each stair has some number of balls.

There are two players who move alternately. On each move, a player chooses a stair k where k≠1 and it has at least one ball. Then, the player moves any number of balls from stair k to stair k−1. The winner is the player who moves last.

Your task is to find out who wins the game when both players play optimally.

Input

The first input line has an integer t: the number of tests. After this, t test cases are described:

The first line contains an integer n: the number of stairs.

The next line has n integers p1,p2,…,pn: the initial number of balls on each stair.

Output

For each test, print "first" if the first player wins the game and "second" if the second player wins the game.

Constraints
1≤t≤2⋅105
1≤n≤2⋅105
0≤pi≤109
the sum of all n is at most 2⋅105
Example

Input:
3
3
0 2 1
4
1 1 1 1
2
5 3

Output:
first
second
first
  */

#include <iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n;
    cin >> n;
    int xr = 0;
    for (int j = 0; j < n; j++){
      int x;
      cin >> x;
      if (j%2 == 1) xr^=x;
    }
    cout << (xr ? "first" : "second") << endl;
  }
}
