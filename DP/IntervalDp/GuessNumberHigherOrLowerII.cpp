/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    vector<vector<int>>dp ; 

    int solve(int l , int r ){

        if(l >= r)
        return 0 ; 
        
        if(dp[l][r] != -1)
        return dp[l][r] ; 
        
        
        int minCost = INT_MAX ; 
        
        for(int x = l ; x <= r ; x ++ ){

            int left  =  solve( l ,  x - 1 ) ;
            int right =  solve( x + 1 , r  ) ; 

            int cost = x + max(left , right) ; 

            minCost = min(minCost , cost) ; 

        }

        return  dp[l][r] = minCost ; 

    }

    int getMoneyAmount(int n) {

        dp.resize( n + 1 , vector<int>(n + 1 , -1)) ; 

        return solve( 1 , n ) ; 
        
    }
};

int main() {

    Solution obj;

    cout << obj.getMoneyAmount(1) << endl;   // Test case 1
    cout << obj.getMoneyAmount(5) << endl;   // Test case 2
    cout << obj.getMoneyAmount(10) << endl;  // Test case 3
    cout << obj.getMoneyAmount(20) << endl;  // Test case 4

    return 0;
}

// Time Complexity : O( l * r)
// Space Complexity : O( l * r)
*/

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    vector<vector<int>>dp ; 

    int solve(int l , int r ){

        if(l >= r)
        return 0 ; 
        
        if(dp[l][r] != -1)
        return dp[l][r] ; 
        
        
        int minCost = INT_MAX ; 
        
        for(int x = l ; x <= r ; x ++ ){

            int left  =  solve( l ,  x - 1 ) ;
            int right =  solve( x + 1 , r  ) ; 

            int cost = x + max(left , right) ; 

            minCost = min(minCost , cost) ; 

        }

        return  dp[l][r] = minCost ; 

    }

    int getMoneyAmount(int n) {

        dp.resize( n + 1 , vector<int>(n + 1 , -1)) ; 

        return solve( 1 , n ) ; 
        
    }
};

int main() {

    Solution obj;

    cout << obj.getMoneyAmount(1) << endl;   // Test case 1
    cout << obj.getMoneyAmount(5) << endl;   // Test case 2
    cout << obj.getMoneyAmount(10) << endl;  // Test case 3
    cout << obj.getMoneyAmount(20) << endl;  // Test case 4

    return 0;
}

// Time Complexity : O( l * r)
// Space Complexity : O( l * r)