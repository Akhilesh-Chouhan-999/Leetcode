/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[401] ; 
    int solve(vector<int>&nums , int target){

        if(target == 0)
        return 1 ; 

        if(target < 0)
        return 0 ; 


        if(memo[target] != -1)
        return memo[target] ; 

        int ans = 0 ; 

        for(int i = 0 ; i < nums.size()  ; i ++ ){
             ans += solve(nums , target - nums[i]) ; 
        }

        return memo[target] =  ans ; 
       
    }


    int combinationSum4(vector<int>& nums, int target){

        memset(memo , -1 , sizeof(memo)) ; 

        return solve(nums , target) ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3};
    int target1 = 4;
    cout << "Output: " << sol.combinationSum4(nums1, target1)
         << " | Expected: 7" << endl;

    // Example 2
    vector<int> nums2 = {9};
    int target2 = 3;
    cout << "Output: " << sol.combinationSum4(nums2, target2)
         << " | Expected: 0" << endl;

    return 0;
}

// Time Complexity : O(target*n)
// Space Complexity : O(target)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int combinationSum4(vector<int>& nums, int target){


        vector<int>dp(target + 1) ; 

        dp[0] = 1 ;

        for(int idx = 1 ; idx <= target ; idx ++ ){

             int ans = 0 ; 

            for(int i = 0 ; i < nums.size()  ; i ++ ){

                if(idx - nums[i] >= 0)
                ans += dp[idx - nums[i] ] ; 

            }

            dp[idx] =  ans ;

        }

        return dp[target] ; 
        

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3};
    int target1 = 4;
    cout << "Output: " << sol.combinationSum4(nums1, target1)
         << " | Expected: 7" << endl;

    // Example 2
    vector<int> nums2 = {9};
    int target2 = 3;
    cout << "Output: " << sol.combinationSum4(nums2, target2)
         << " | Expected: 0" << endl;

    return 0;
}

// Time Complexity : O(target*n)
// Space Complexity : O(target)