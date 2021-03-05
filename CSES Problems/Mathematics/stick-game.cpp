/* Consider a game where two players remove sticks from a heap. The players move alternately, and the player who removes the last stick wins the game.

A set P={p1,p2,…,pk} determines the allowed moves. For example, if P={1,3,4}, a player may remove 1, 3 or 4 sticks.

Your task is find out for each number of sticks 1,2,…,n if the first player has a winning or losing position.

Input

The first input line has two integers n and k: the number of sticks and moves.

The next line has k integers p1,p2,…,pk that describe the allowed moves. All integers are distinct, and one of them is 1.

Output

Print a string containing n characters: W means a winning position, and L means a losing position.

Constraints
1≤n≤106
1≤k≤100
1≤pi≤n
Example

Input:
10 3
1 3 4

Output:
WLWWWWLWLW
*/

#include <iostream>
using namespace std;
int N, K, opt[100];
bool dp[1000001];

int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> opt[i];
    }
    dp[0] = false;
    for(int i= 1; i <=N; i++){
        dp[i] = false;
        for(int j = 0; j < K; j++){
            if(i-opt[j] >= 0 && !dp[i-opt[j]]){
                dp[i] = true;
                break;
            }
        }
        dp[i] ? cout << "W" : cout << "L";
    }
}