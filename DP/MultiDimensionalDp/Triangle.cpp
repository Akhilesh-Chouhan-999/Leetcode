/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int row;

    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){

        if(i == row - 1)
            return triangle[i][j];

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = solve(triangle, i + 1, j, dp);
        int diag = solve(triangle, i + 1, j + 1, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle){

        row = triangle.size();

        vector<vector<int>> dp(row, vector<int>(row, INT_MAX));

        return solve(triangle, 0, 0, dp);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> triangle1 = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << "Output: " << sol.minimumTotal(triangle1)
         << " | Expected: 11" << endl;

    // Example 2
    vector<vector<int>> triangle2 = {
        {-10}
    };
    cout << "Output: " << sol.minimumTotal(triangle2)
         << " | Expected: -10" << endl;

    return 0;
}

Time Complexity : O(n^2)
Space Complexity : O(n^2)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    int minimumTotal(vector<vector<int>>& triangle){

        int n =  triangle.size();

        vector<vector<int>> dp(n , vector<int>(n , INT_MAX));

        for(int i = 0 ; i < n ; i ++){
          dp[n-1][i] = triangle[n-1][i] ;
        }

        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i ; j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0] ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> triangle1 = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << "Output: " << sol.minimumTotal(triangle1)
         << " | Expected: 11" << endl;

    // Example 2
    vector<vector<int>> triangle2 = {
        {-10}
    };
    cout << "Output: " << sol.minimumTotal(triangle2)
         << " | Expected: -10" << endl;

    return 0;
}