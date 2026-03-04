/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n ; 

    int solve(vector<int>&num , int idx){

        if(idx >= n ){
            return 0 ; 
        }

        int take = num[idx] + solve(num , idx + 2) ; 
        int skip =  solve(num , idx + 1) ; 


        return max(take , skip) ; 


    }


    int rob(vector<int>& nums){

        n = nums.size() ; 


        return max(solve(nums , 0), solve(nums , 1)) ; 

    }
};

int main() {
    Solution obj;

    vector<int> test1 = {1,2,3,1};
    vector<int> test2 = {2,7,9,3,1};
    vector<int> test3 = {2,1,1,2};
    vector<int> test4 = {5};

    cout << "Test Case 1" << endl;
    cout << "Input: [1,2,3,1]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: [2,7,9,3,1]" << endl;
    cout << "Expected Output: 12" << endl;
    cout << "Your Output: " << obj.rob(test2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: [2,1,1,2]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: [5]" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.rob(test4) << endl;

    return 0;
}


Time Complexity : O(2 ^ n)
Space Complexity : O(n)




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n ; 
    int memo[101] ; 

    int solve(vector<int>&num , int idx){

        if(idx >= n ){
            return 0 ; 
        }

        if(memo[idx] != -1)
        return memo[idx] ; 

        int take = num[idx] + solve(num , idx + 2) ; 
        int skip =  solve(num , idx + 1) ; 


        return memo[idx] = max(take , skip) ; 

    }


    int rob(vector<int>& nums){

        n = nums.size() ; 
        memset(memo ,-1 , sizeof(memo)) ;

        return  max(solve(nums , 0), solve(nums , 1)) ; 

    }
};

int main() {
    Solution obj;

    vector<int> test1 = {1,2,3,1};
    vector<int> test2 = {2,7,9,3,1};
    vector<int> test3 = {2,1,1,2};
    vector<int> test4 = {5};

    cout << "Test Case 1" << endl;
    cout << "Input: [1,2,3,1]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: [2,7,9,3,1]" << endl;
    cout << "Expected Output: 12" << endl;
    cout << "Your Output: " << obj.rob(test2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: [2,1,1,2]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: [5]" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.rob(test4) << endl;

    return 0;
}

Time Complexity : O(n)
Space Complexity : O(n)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

 
    // int take = num[idx] + solve(num , idx + 2) ; 
    // int skip =  solve(num , idx + 1) ; 

    int rob(vector<int>& nums){

        int n = nums.size() ; 

        vector<int>dp( n , 0) ;
    
        dp[0] = nums[0] ;
        dp[1] = max(nums[0]  , nums[1]); 

        for(int i = 2 ; i < n ; i ++ ){
            dp[i] = max(nums[i] + dp[i-2] , dp[i-1]) ;
        }


        return dp[n-1] ; 
    }
};

int main() {
    Solution obj;

    vector<int> test1 = {1,2,3,1};
    vector<int> test2 = {2,7,9,3,1};
    vector<int> test3 = {2,1,1,2};
    vector<int> test4 = {5};

    cout << "Test Case 1" << endl;
    cout << "Input: [1,2,3,1]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: [2,7,9,3,1]" << endl;
    cout << "Expected Output: 12" << endl;
    cout << "Your Output: " << obj.rob(test2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: [2,1,1,2]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: [5]" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.rob(test4) << endl;

    return 0;
}

Time Complexity : O(n)
Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums){

        int n = nums.size() ; 

        if( n == 1)
        return nums[0] ; 

        int a = nums[0] ; 
        int b = max(nums[0] , nums[1])  ;
        int c  ; 
        
        for(int i = 2 ; i < n ; i ++ ){
            c = max(nums[i] + a , b) ; 
            a = b ; 
            b = c ; 
        }

        return b;  
    }
};

int main() {
    Solution obj;

    vector<int> test1 = {1,2,3,1};
    vector<int> test2 = {2,7,9,3,1};
    vector<int> test3 = {2,1,1,2};
    vector<int> test4 = {5};

    cout << "Test Case 1" << endl;
    cout << "Input: [1,2,3,1]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test1) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: [2,7,9,3,1]" << endl;
    cout << "Expected Output: 12" << endl;
    cout << "Your Output: " << obj.rob(test2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: [2,1,1,2]" << endl;
    cout << "Expected Output: 4" << endl;
    cout << "Your Output: " << obj.rob(test3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: [5]" << endl;
    cout << "Expected Output: 5" << endl;
    cout << "Your Output: " << obj.rob(test4) << endl;

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1)