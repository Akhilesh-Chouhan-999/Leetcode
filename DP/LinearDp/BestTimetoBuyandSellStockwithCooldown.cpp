/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int memo[5001][2]  ; 

    int solve(vector<int>&prices , int idx , bool holding ){

        if(idx >= prices.size()){
            return 0 ; 
        }

        if(memo[idx][holding] != -1)
        return memo[idx][holding] ; 

        if(!holding){
            int buy = -prices[idx] + solve(prices , idx + 1 , true) ;
            int skip = solve(prices , idx + 1 , false) ; 
            return memo[idx][holding] = max(buy , skip) ; 
        }else{
            int sell = prices[idx] + solve(prices  , idx + 2 , false) ; 
            int skip = solve(prices , idx + 1 , true) ; 
            return memo[idx][holding] = max(sell ,skip) ; 
        }

    }


    int maxProfit(vector<int>& prices) {
        memset(memo , -1 , sizeof(memo)) ;
        return solve(prices , 0 , false) ; 
    }
};

int main() {

    Solution obj;

    vector<int> test1 = {1,2,3,0,2};
    vector<int> test2 = {1};
    vector<int> test3 = {6,1,3,2,4,7};
    vector<int> test4 = {1,2,4};

    cout << "Test Case 1" << endl;
    cout << "Input: [1,2,3,0,2]" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.maxProfit(test1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: [1]" << endl;
    cout << "Expected Output: 0" << endl;
    cout << "Your Output: " << obj.maxProfit(test2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: [6,1,3,2,4,7]" << endl;
    cout << "Expected Output: 6" << endl;
    cout << "Your Output: " << obj.maxProfit(test3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: [1,2,4]" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.maxProfit(test4) << endl;

    return 0;
}

// Time Complexity : O(2*n)
// Space Complexity : O(2*n)
*/


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ; 

        vector<vector<int>>dp ( n + 1 , vector<int>( 2 , 0)) ; 

        for(int idx = n - 1 ; idx >= 0 ; idx -- ){

            dp[idx][0] = max(-prices[idx] + dp[idx+1][1] , dp[idx+1][0] ) ;
            dp[idx][1] = max( prices[idx] + dp[idx+2][0] , dp[idx+1][1]) ;
        }

        return dp[0][0] ; 
     
    }
};

int main() {

    Solution obj;

    vector<int> test1 = {1,2,3,0,2};
    vector<int> test2 = {1};
    vector<int> test3 = {6,1,3,2,4,7};
    vector<int> test4 = {1,2,4};

    cout << "Test Case 1" << endl;
    cout << "Input: [1,2,3,0,2]" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.maxProfit(test1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: [1]" << endl;
    cout << "Expected Output: 0" << endl;
    cout << "Your Output: " << obj.maxProfit(test2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: [6,1,3,2,4,7]" << endl;
    cout << "Expected Output: 6" << endl;
    cout << "Your Output: " << obj.maxProfit(test3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: [1,2,4]" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.maxProfit(test4) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(2*n)