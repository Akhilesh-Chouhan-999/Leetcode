/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    vector<vector<int>>dp ; 
    // dp[index][amount]  Number of ways to form amount using coins from index onward. 
public:
    int solve(int amount, vector<int> &coins , int index , vector<vector<int>>&dp ){

        if (amount == 0 )
            return 1;

        if (amount < 0 || index >= dp.size())
            return 0;


        if(dp[index][amount] != -1)
        return dp[index][amount] ; 


        int total = 0;

        for (int i = index ; i < coins.size(); i++)
        {

            if (amount >= coins[i])
            {
                total += solve(amount - coins[i], coins  , i , dp );
            }
        }

        return dp[index][amount] =  total;
    }


    int change(int amount, vector<int> &coins)
    {

        int m = coins.size()  ; 

        dp.resize(m , vector<int>(amount + 1 , -1)) ; 


        int result = solve(amount , coins , 0 , dp ) ;

        return result ; 
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};
    cout << "Test Case 1" << endl;
    cout << "Input: amount = 5, coins = [1,2,5]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Function Output: " << sol.change(amount1, coins1) << endl;
    cout << "-----------------------------" << endl;

    // Test Case 2
    int amount2 = 3;
    vector<int> coins2 = {2};
    cout << "Test Case 2" << endl;
    cout << "Input: amount = 3, coins = [2]" << endl;
    cout << "Expected Output: 0" << endl;
    cout << "Function Output: " << sol.change(amount2, coins2) << endl;
    cout << "-----------------------------" << endl;

    // Test Case 3
    int amount3 = 10;
    vector<int> coins3 = {10};
    cout << "Test Case 3" << endl;
    cout << "Input: amount = 10, coins = [10]" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Function Output: " << sol.change(amount3, coins3) << endl;
    cout << "-----------------------------" << endl;

    // Edge Case: amount = 0
    int amount4 = 0;
    vector<int> coins4 = {1, 2, 3};
    cout << "Test Case 4 (Edge Case)" << endl;
    cout << "Input: amount = 0, coins = [1,2,3]" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Function Output: " << sol.change(amount4, coins4) << endl;
    cout << "-----------------------------" << endl;

    return 0;
}
Recursive Solution TC : O(N ^ A)
                   SC : O(A)

Memoized solution TC : O( n * amount * n ) => O( n ^ 2 * amount)
                  SC : o( n * amount )
           
	​

*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    vector<vector<int>>dp ; 
    // dp[index][amount]  Number of ways to form amount using coins from index onward. 
public:
    int solve(int amount, vector<int> &coins , int index , vector<vector<int>>&dp ){

        if (amount == 0 )
            return 1;

        if (amount < 0 || index >= dp.size())
            return 0;


        if(dp[index][amount] != -1)
        return dp[index][amount] ; 


        int total = 0;

        for (int i = index ; i < coins.size(); i++)
        {

            if (amount >= coins[i])
            {
                total += solve(amount - coins[i], coins  , i , dp );
            }
        }

        return dp[index][amount] =  total;
    }


    int change(int amount, vector<int> &coins)
    {

        int m = coins.size()  ; 

        dp.resize(m , vector<int>(amount + 1 , -1)) ; 


        int result = solve(amount , coins , 0 , dp ) ;

        return result ; 
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};
    cout << "Test Case 1" << endl;
    cout << "Input: amount = 5, coins = [1,2,5]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Function Output: " << sol.change(amount1, coins1) << endl;
    cout << "-----------------------------" << endl;

    // Test Case 2
    int amount2 = 3;
    vector<int> coins2 = {2};
    cout << "Test Case 2" << endl;
    cout << "Input: amount = 3, coins = [2]" << endl;
    cout << "Expected Output: 0" << endl;
    cout << "Function Output: " << sol.change(amount2, coins2) << endl;
    cout << "-----------------------------" << endl;

    // Test Case 3
    int amount3 = 10;
    vector<int> coins3 = {10};
    cout << "Test Case 3" << endl;
    cout << "Input: amount = 10, coins = [10]" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Function Output: " << sol.change(amount3, coins3) << endl;
    cout << "-----------------------------" << endl;

    // Edge Case: amount = 0
    int amount4 = 0;
    vector<int> coins4 = {1, 2, 3};
    cout << "Test Case 4 (Edge Case)" << endl;
    cout << "Input: amount = 0, coins = [1,2,3]" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Function Output: " << sol.change(amount4, coins4) << endl;
    cout << "-----------------------------" << endl;

    return 0;
}


