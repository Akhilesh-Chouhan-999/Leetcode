#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>&nums, int l, int r){

        if( r - l + 1 < 3)
        return 0 ; 


        bool check = true ; 

        for(int idx = l + 1 ; idx <= r ; idx ++){

            if(nums[idx+1] - nums[idx] != nums[idx] - nums[idx-1]){
                check = false ; 
                break;
            }
            
        }

        return check == true + solve(nums , ) ; 

    }


    int numberOfArithmeticSlices(vector<int>& nums){

        int n = nums.size() ; 

        return solve(nums , 0 , n) ;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3,4};
    cout << "Output: " << sol.numberOfArithmeticSlices(nums1)
         << " | Expected: 3" << endl;

    // Example 2
    vector<int> nums2 = {1};
    cout << "Output: " << sol.numberOfArithmeticSlices(nums2)
         << " | Expected: 0" << endl;

    return 0;
}