#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int M , N ; 
    vector<vector<vector<double>>> memo;


    double solve(int row , int col , int moves){

        if(row < 0 || col < 0 || row >= M || col >= N){
            return 0 ; 
        }

        if(moves == 0)
            return 1 ; 

        if(memo[row][col][moves] != -1)
        return memo[row][col][moves] ; 

        int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
        int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

        double probability = 0;

        for (int i = 0; i < 8; i++) {
            probability += solve(row + dx[i], col + dy[i], moves - 1) / 8.0;
        }

        return memo[row][col][moves] = probability; 
    }

    double knightProbability(int n, int k, int row, int column){

        this -> M = n ; 
        this -> N = n ; 
        memo = vector<vector<vector<double>>>
             (n, vector<vector<double>>(n, vector<double>(k+1, -1))); 


        return solve(row, column, k);
    }
};

int main() {
    Solution sol;

    cout << fixed << setprecision(5);

    // Example 1
    cout << "Output: " << sol.knightProbability(3, 2, 0, 0)
         << " | Expected: 0.06250" << endl;

    // Example 2
    cout << "Output: " << sol.knightProbability(1, 0, 0, 0)
         << " | Expected: 1.00000" << endl;

    return 0;
}

// Time Complexity : O(row * col * moves)
// Space Complexity : O(row * col * moves)