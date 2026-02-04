#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int minCoin = INT_MAX ; 

    void solve( int amount , vector<int>&coins , int countCoin){

        if(amount == 0){
            minCoin = min(minCoin , countCoin) ; 
            return ; 
        }

        if(amount < 0  || minCoin < countCoin ){
            return ; 
        }
        
        for(int i = 0 ; i < coins.size() ; i ++ ){

            if(amount >= coins[i]){
                solve(amount - coins[i] , coins , countCoin + 1 ) ; 
            }
        }

        return ; 

    }
    int coinChange(vector<int>& coins, int amount) {

        solve(amount , coins , 0 ) ; 

        return minCoin == INT_MAX ? -1 : minCoin ; 

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