#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int M , N ; 
    int memo[52][52][52] ;
    const int MOD = 1000000007;

    int solve(int row ,  int col , int maxMove){

        
        if(row < 0 || col < 0 || row == M || col == N){
            return 1 ; 
        }


        if(maxMove == 0)
        return 0 ; 

        if(memo[row][col][maxMove] != -1)
        return memo[row][col][maxMove] ; 


        int left   = solve(row     , col - 1 , maxMove - 1) ;
        int right  = solve(row     , col + 1 , maxMove - 1) ; 
        int top    = solve(row - 1 , col     , maxMove - 1) ; 
        int bottom = solve(row + 1 , col     , maxMove - 1) ; 

        
        return memo[row][col][maxMove] = ((long long)left + right + top + bottom) % MOD;  
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn){

        this -> M = m ; 
        this -> N = n ; 
        memset(memo , -1 , sizeof(memo)) ;

        return solve( startRow , startColumn , maxMove) ;
    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.findPaths(2, 2, 2, 0, 0)
         << " | Expected: 6" << endl;

    // Example 2
    cout << "Output: " << sol.findPaths(1, 3, 3, 0, 1)
         << " | Expected: 12" << endl;

    return 0;
}

// Time Complexity : O(row * col * maxMoves)
// Space Complexity : O(row * col * maxMoves)

