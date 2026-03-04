/*
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int n  ;
    vector<vector<int>>memo ; 

    int solve(vector<int>&coins  , int idx , int amount ){

        if(amount == 0)
        return 0 ; 

        if(amount < 0 || idx >= n)
        return INT_MAX ;

        if(memo[idx][amount] != -1)
        return memo[idx][amount] ; 


        int temp = min(solve(coins, idx + 1, amount-coins[idx] )  , solve(coins, idx, amount - coins[idx])) ;

        int takeCurrentCoin;

        if(temp != INT_MAX)
        takeCurrentCoin = 1 + temp;
        else
        takeCurrentCoin = INT_MAX ;  

        int skipCurrentCoin = solve(coins , idx + 1 , amount ) ;

        return memo[idx][amount]= min(takeCurrentCoin , skipCurrentCoin)  ; 

    }


    int coinChange(vector<int>& coins, int amount) {

          n = coins.size() ;
          
          memo.resize(n + 1 , vector<int>(amount+1 , -1)) ;

          int result = solve(coins , 0 , amount) ; 

          return result == INT_MAX ? -1 : result ; 
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1 Output: "
         << sol.coinChange(coins1, amount1)
         << " | Expected: 3" << endl;

    // Reset object for next test
    sol = Solution();

    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: "
         << sol.coinChange(coins2, amount2)
         << " | Expected: -1" << endl;

    // Reset object for next test
    sol = Solution();

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3 Output: "
         << sol.coinChange(coins3, amount3)
         << " | Expected: 0" << endl;

    return 0;
}


// Time Complexity : O(n * amount)
// Space Complexity : O(n * amount)
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

      
        for (int amt = 1; amt <= amount; amt++)
            dp[n][amt] = INT_MAX;

        dp[n][0] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            
            for (int amt = 0; amt <= amount; amt++) {

                if (amt == 0) {
                    dp[idx][amt] = 0;
                    continue;
                }

                int take = INT_MAX;

                if (amt - coins[idx] >= 0) {

                    int val1 = dp[idx + 1][amt - coins[idx]];
                    int val2 = dp[idx][amt - coins[idx]];

                    int temp = min(val1, val2);

                    if (temp != INT_MAX)
                        take = 1 + temp;
                }

                int skip = dp[idx + 1][amt];

                dp[idx][amt] = min(take, skip);
            }
        }

        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1 Output: "
         << sol.coinChange(coins1, amount1)
         << " | Expected: 3" << endl;

    // Reset object for next test
    sol = Solution();

    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: "
         << sol.coinChange(coins2, amount2)
         << " | Expected: -1" << endl;

    // Reset object for next test
    sol = Solution();

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3 Output: "
         << sol.coinChange(coins3, amount3)
         << " | Expected: 0" << endl;

    return 0;
}


// Time Complexity : O(n * amount)
// Space Complexity : O(n * amount)