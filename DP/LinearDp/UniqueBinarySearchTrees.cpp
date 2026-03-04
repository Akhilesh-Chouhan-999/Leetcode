/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int n){

        // Base Case :
        if( n <= 1)
        return 1 ;

        int result = 0 ;

        for(int i = 1 ; i <= n ;  i ++ ){
            result += solve( i - 1 ) * solve( n - i ) ;
        }

        return result ;
    }
    int numTrees(int n){

       return solve(n) ;

    }
};

int main() {
    Solution obj;

    cout << "Test Case 1" << endl;
    cout << "Input: 1" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Your Output: " << obj.numTrees(1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.numTrees(2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: 3" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.numTrees(3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: 4" << endl;
    cout << "Expected Output: 14" << endl;
    cout << "Your Output: " << obj.numTrees(4) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 5" << endl;
    cout << "Input: 5" << endl;
    cout << "Expected Output: 42" << endl;
    cout << "Your Output: " << obj.numTrees(5) << endl;

    return 0;
}

Time Complexity : O(2^n)
Space Complexity : O(n)




#include <bits/stdc++.h>
using namespace std;

int memo[20] ;

class Solution {
public:

    int solve(int n){
        if( n <= 1)
        return 1 ;

        if(memo[n] != -1)
        return memo[n] ;

        int result = 0 ;

        for(int i = 1 ; i <= n ;  i ++ ){
            result += solve( i - 1 ) * solve( n - i ) ;
        }

        return memo[n] = result ;
    }
    int numTrees(int n){

       memset(memo , -1 , sizeof(memo)) ;
       return solve(n) ;

    }
};

int main() {
    Solution obj;

    cout << "Test Case 1" << endl;
    cout << "Input: 1" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Your Output: " << obj.numTrees(1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.numTrees(2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: 3" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.numTrees(3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: 4" << endl;
    cout << "Expected Output: 14" << endl;
    cout << "Your Output: " << obj.numTrees(4) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 5" << endl;
    cout << "Input: 5" << endl;
    cout << "Expected Output: 42" << endl;
    cout << "Your Output: " << obj.numTrees(5) << endl;

    return 0;
}

Time Complexity : O(n^2)
Space Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++){

            int ways = 0;

            for (int j = 1 ; j <= i ; j ++){

                ways += dp[j-1] * dp[i-j] ; 

            }

            dp[i]= ways ; 
        }

        return dp[n] ; 
    }
};

int main()
{
    Solution obj;

    cout << "Test Case 1" << endl;
    cout << "Input: 1" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Your Output: " << obj.numTrees(1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.numTrees(2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: 3" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.numTrees(3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: 4" << endl;
    cout << "Expected Output: 14" << endl;
    cout << "Your Output: " << obj.numTrees(4) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 5" << endl;
    cout << "Input: 5" << endl;
    cout << "Expected Output: 42" << endl;
    cout << "Your Output: " << obj.numTrees(5) << endl;

    return 0;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n) 
