/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n ){

        if(n == 0)
        return 1 ;
        
        if( n < 0)
        return 0 ; 

        int oneStep = solve(n-1) ; 
        int twoStep = solve(n-2) ; 

        return oneStep + twoStep ; 
    }

    int climbStairs(int n){

        return solve(n) ; 

    }
};

int main() {
    Solution obj;

    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.climbStairs(2) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 3" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.climbStairs(3) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 5" << endl;
    cout << "Expected Output: 8" << endl;
    cout << "Your Output: " << obj.climbStairs(5) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 10" << endl;
    cout << "Expected Output: 89" << endl;
    cout << "Your Output: " << obj.climbStairs(10) << endl;

    return 0;
}

// Time Complexity : O(2^n)
// Space Complexity : O(n)





#include <bits/stdc++.h>
using namespace std;

vector<int>dp  ; 
// dp[i] = total way to reach to bottom from the ith stair . 

class Solution {
public:
    int solve(int n ){

        if(n == 0)
        return 1 ;
        
        if( n < 0)
        return 0 ; 

        if(dp[n] != -1)
        return dp[n] ; 

        int oneStep = solve(n-1) ; 
        int twoStep = solve(n-2) ; 

        return dp[n] =  oneStep + twoStep ; 
    }

    int climbStairs(int n){
        dp.resize(n + 1  , -1) ; 
        return solve(n) ; 

    }
};

int main() {
    Solution obj;

    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.climbStairs(2) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 3" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.climbStairs(3) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 5" << endl;
    cout << "Expected Output: 8" << endl;
    cout << "Your Output: " << obj.climbStairs(5) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 10" << endl;
    cout << "Expected Output: 89" << endl;
    cout << "Your Output: " << obj.climbStairs(10) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)





#include <bits/stdc++.h>
using namespace std;

vector<int>dp  ; 


class Solution {
public:
    

    int climbStairs(int n){

        vector<int>dp( n + 2 , 0) ;
        dp[n] = 1 ; 

        for(int i = n - 1; i >= 0 ; i -- ){
            dp[i] = dp[i+1] + dp[i+2] ; 
        }

        return dp[0] ; 

    }
};

int main() {
    Solution obj;

    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.climbStairs(2) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 3" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.climbStairs(3) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 5" << endl;
    cout << "Expected Output: 8" << endl;
    cout << "Your Output: " << obj.climbStairs(5) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 10" << endl;
    cout << "Expected Output: 89" << endl;
    cout << "Your Output: " << obj.climbStairs(10) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)



*/




#include <bits/stdc++.h>
using namespace std;

vector<int>dp  ; 


class Solution {
public:
    

    int climbStairs(int n){

        int a = 0 ; 
        int b = 1 ; 
        int c  ;

        for(int i = n - 1 ; i >= 0 ; i -- ){

            c = a + b ; 

            a = b ; 
            
            b = c ; 
        }

        return c; 

    }
};

int main() {
    Solution obj;

    cout << "Input: 2" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Your Output: " << obj.climbStairs(2) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 3" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Your Output: " << obj.climbStairs(3) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 5" << endl;
    cout << "Expected Output: 8" << endl;
    cout << "Your Output: " << obj.climbStairs(5) << endl;
    cout << "--------------------------" << endl;

    cout << "Input: 10" << endl;
    cout << "Expected Output: 89" << endl;
    cout << "Your Output: " << obj.climbStairs(10) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

