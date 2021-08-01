/*
 * There are n heaps of sticks and two players who move alternately. On each move, a player chooses a non-empty heap and removes any number of sticks. The player who removes the last stick wins the game.

Your task is to find out who wins if both players play optimally.

Input

The first input line contains an integer t: the number of tests. After this, t test cases are described:

The first line contains an integer n: the number of heaps.

The next line has n integers x1,x2,…,xn: the number of sticks in each heap.

Output

For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.

Constraints
1≤t≤2⋅105
1≤n≤2⋅105
1≤xi≤109
the sum of all n is at most 2⋅105
Example

Input:
3
4
5 7 2 5
2
4 1
3
3 5 6

Output:
first
first
second
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
    for(int i =0; i < n; i++){
      int a;
      cin >> a;
      xr ^=a%4;
    }
    xr == 0 ? cout << "second" : cout << "first";
    cout << endl;
  }
}
