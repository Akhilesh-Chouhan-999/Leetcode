#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  
    int solve(vector<int>&nums1 , vector<int>&nums2 , int idx ){

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2){

        int n = nums1.size() ; 

        return solve(nums1 , nums2 , n  - 1  ) ;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1_1 = {1,3,5,4};
    vector<int> nums2_1 = {1,2,3,7};
    cout << "Output: " << sol.minSwap(nums1_1, nums2_1)
         << " | Expected: 1" << endl;

    // Example 2
    vector<int> nums1_2 = {0,3,5,8,9};
    vector<int> nums2_2 = {2,1,4,6,9};
    cout << "Output: " << sol.minSwap(nums1_2, nums2_2)
         << " | Expected: 1" << endl;

    return 0;
}