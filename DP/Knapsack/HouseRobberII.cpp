#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[1001] ;

    int solve(vector<int>nums , int n  , int idx){

        if(idx >= n)
        return 0 ; 

        if(memo[idx] != -1)
        return memo[idx] ; 


        int take = nums[idx] + solve(nums , n , idx + 2) ;
        int skip = solve(nums , n , idx + 1) ;

        return memo[idx] = max(take , skip) ; 

    }


    int rob(vector<int>& nums){

        int n = nums.size() ; 

        memset(memo , -1 , sizeof(memo)) ;
        int case1 = solve(nums , n - 1 , 0 ) ; 

        memset(memo , -1 , sizeof(memo)) ; 
        int case2 = solve(nums , n , 1 ) ;

        return max(case1 , case2) ;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2,3,2};
    cout << "Output: " << sol.rob(nums1)
         << " | Expected: 3" << endl;

    // Example 2
    vector<int> nums2 = {1,2,3,1};
    cout << "Output: " << sol.rob(nums2)
         << " | Expected: 4" << endl;

    // Example 3
    vector<int> nums3 = {1,2,3};
    cout << "Output: " << sol.rob(nums3)
         << " | Expected: 3" << endl;

    return 0;
}