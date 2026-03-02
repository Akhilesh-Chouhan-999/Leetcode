#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

   vector<vector<int>>dp ; 
   const int MOD = 1000000007;

    int solve(int n, int k, int target){

        if(target == 0 && n == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][target] != -1) 
        return dp[n][target];

        int cntWay = 0;


        for(int i = 1; i <= k; i++){
            if(i <= target){
                cntWay = (cntWay + solve(n-1, k, target-i)) % MOD;
            }
        }

        return dp[n][target] = cntWay;
    }


    int numRollsToTarget(int n, int k, int target) {

        dp.resize(n + 1 , vector<int>( target + 1 , -1) ) ; 
        
        return solve(n , k , target) ;

    }
};

int main() {
    Solution sol;

    // Test Case 1
    int n1 = 1, k1 = 6, target1 = 3;
    cout << "Test 1 Output: " 
         << sol.numRollsToTarget(n1, k1, target1) << endl;

    // Test Case 2
    int n2 = 2, k2 = 6, target2 = 7;
    cout << "Test 2 Output: " 
         << sol.numRollsToTarget(n2, k2, target2) << endl;

    // Test Case 3
    int n3 = 3, k3 = 6, target3 = 8;
    cout << "Test 3 Output: " 
         << sol.numRollsToTarget(n3, k3, target3) << endl;

    // Edge Case
    int n4 = 2, k4 = 5, target4 = 1;
    cout << "Test 4 Output: " 
         << sol.numRollsToTarget(n4, k4, target4) << endl;

    return 0;
}

// Time Complexity : O(n * k * t)
// Space Complexity : O( n * t)