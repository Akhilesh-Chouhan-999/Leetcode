#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    vector<vector<int>> dp ; 
    int offset ; 


    int solve(vector<int>&nums ,int index ,  int sum , int &target){

         if( index == nums.size())
         return sum == target ; 

         if(dp[index][offset + sum] != -1)
         return dp[index][offset+sum] ; 

         int calWays = 0 ;

        calWays += solve(nums , index + 1 , sum + nums[index] , target) ; 
         
       
         calWays +=  solve(nums , index + 1 , sum - nums[index], target) ;  


         return dp[index][sum + offset] = calWays ; 

    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0 ; 

        for(int num : nums) sum += num ;

        offset = sum ; 

        dp.resize(nums.size() , vector<int>( 2 * offset + 1 , -1)) ; 
        
        int result =  solve(nums , 0 , 0 , target) ; 

         return result  ; 
    }
};


int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Test Case 1 Output: "
         << sol.findTargetSumWays(nums1, target1)
         << " | Expected: 5\n";

    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Test Case 2 Output: "
         << sol.findTargetSumWays(nums2, target2)
         << " | Expected: 1\n";

    return 0;
}


// Offset : offset is the maximum absolute value that the running sum can reach.
// dp[index][sum + offset] : Number of ways to reach target using elements from index to n-1 , given that the current accumulated sum is sum.
// Time Complexity : Number of dp State => index * offset ( 2 * sum + 1 )
// Space Complexity : O(n × offset)
