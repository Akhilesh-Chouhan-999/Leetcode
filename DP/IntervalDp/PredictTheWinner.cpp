/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[21][21] ;

    int solve(vector<int>&nums , int start , int end ){

        if(start == end)return nums[start] ; 
        if(start > end )return 0 ; 

        if(memo[start][end] != -1)
        return memo[start][end] ; 

        int left  = nums[start]  - solve(nums , start + 1 , end) ; 
        int right = nums[end]    - solve(nums , start     , end - 1 ) ; 

        return max(left , right) ; 

    }

    bool predictTheWinner(vector<int>& nums){


        memset(memo , -1 , sizeof(memo)) ; 
        return solve(nums , 0 , nums.size() - 1) >= 0; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,5,2};
    cout << "Output: " << sol.predictTheWinner(nums1)
         << " | Expected: false" << endl;

    // Example 2
    vector<int> nums2 = {1,5,233,7};
    cout << "Output: " << sol.predictTheWinner(nums2)
         << " | Expected: true" << endl;

    return 0;
}


// Time Complexity : O(n*n)
// Space Complexity : O(n*n)


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    bool predictTheWinner(vector<int>& nums){

        int n = nums.size() ; 

        vector<vector<int>>dp(n , vector<int>(n , -1)) ; 

        for(int i = 0 ; i < n ; i ++ ){
            dp[i][i] = nums[i] ; 
        }

       

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,5,2};
    cout << "Output: " << sol.predictTheWinner(nums1)
         << " | Expected: false" << endl;

    // Example 2
    vector<int> nums2 = {1,5,233,7};
    cout << "Output: " << sol.predictTheWinner(nums2)
         << " | Expected: true" << endl;

    return 0;
}


// Time Complexity : O(n*n)
// Space Complexity : O(n*n)
