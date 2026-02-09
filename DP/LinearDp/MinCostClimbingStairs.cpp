/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n ;
    int minCost ; 
    void solve(vector<int>&costs , int currCost ,  int idx ){

        if(idx >= n){
            minCost = min(currCost , minCost) ; 
            return  ; 
        }

        // Take first stair from the position idx
         solve(costs , currCost + costs[idx] , idx + 1)  ; 

         // Take second stair from teh position idx 
         solve(costs , currCost + costs[idx] , idx + 2 ) ; 

         return   ; 

    }
    int minCostClimbingStairs(vector<int>& cost){

        n = cost.size()  ;
        minCost = INT_MAX ; 

        solve(cost , 0 , 0 ) ;
        solve(cost , 0 , 1 ) ; 

        return minCost ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> cost1 = {10, 15, 20};
    cout << "Output: " << sol.minCostClimbingStairs(cost1)
         << " | Expected: 15" << endl;

    // ---------- Example 2 ----------
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Output: " << sol.minCostClimbingStairs(cost2)
         << " | Expected: 6" << endl;

    return 0;
}

Time Complexity : O(2 ^ n )
Space Compleixty  : O(n)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n ; 
    vector<int>dp ; 

    int solve(vector<int>&costs ,   int idx ){

        if(idx >= n){
            return 0 ; 
        }

        if(dp[idx] != -1)
        return dp[idx] ; 

        int oneStep =  costs[idx] +  solve(costs , idx + 1 ) ; 
        int twoStep =  costs[idx] +  solve(costs , idx + 2 ) ; 

        return dp[idx] = min(oneStep , twoStep) ;
       

    }
    int minCostClimbingStairs(vector<int>& cost){

        n = cost.size() ;
        dp.assign(n , -1) ; 

        return min(solve(cost , 0) , solve(cost , 1)) ;

    }
};
int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> cost1 = {10, 15, 20};
    cout << "Output: " << sol.minCostClimbingStairs(cost1)
         << " | Expected: 15" << endl;

    // ---------- Example 2 ----------
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Output: " << sol.minCostClimbingStairs(cost2)
         << " | Expected: 6" << endl;

    return 0;
}

Time Complexity : O(n)
Space Complexity : O(n)




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost){

        int n = cost.size() ; 

        vector<int>dp( n+2 , 0 ) ;

        for(int i = n - 1 ; i >= 0 ; i -- ){
            dp[i] = cost[i] + min(dp[i+1] , dp[i+1]) ; 
        }

        return min(dp[0] , dp[1] ) ;
    }
};
int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> cost1 = {10, 15, 20};
    cout << "Output: " << sol.minCostClimbingStairs(cost1)
         << " | Expected: 15" << endl;

    // ---------- Example 2 ----------
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Output: " << sol.minCostClimbingStairs(cost2)
         << " | Expected: 6" << endl;

    return 0;
}


Time Complexity : O(n)
Space Complexity : O(n)
*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost){

        int n = cost.size() ; 

        int next1 = 0 ; 
        int next2 = 0 ; 
        int result = INT_MAX ; 


        for(int i = n - 1 ; i >= 0 ; i -- ){

            int currCost = 0 ; 
            currCost = cost[i] + min(next1 , next2) ; 
            next2 = next1 ; 
            next1 = currCost ; 
        }

       return min(next1 , next2) ; 
    }
};
int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> cost1 = {10, 15, 20};
    cout << "Output: " << sol.minCostClimbingStairs(cost1)
         << " | Expected: 15" << endl;

    // ---------- Example 2 ----------
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Output: " << sol.minCostClimbingStairs(cost2)
         << " | Expected: 6" << endl;

    return 0;
}



