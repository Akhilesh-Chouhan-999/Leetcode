#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {

        int n = nums.size() ; 

        unordered_map<int , int>mpp ; 

        for(int i = 0 ; i < n ; i ++ ){
            
            if(nums[i] == target[i]) continue;

            mpp[nums[i]] ++ ;

        }

        return mpp.size() ; 
    }
 };

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> target1 = {2, 1, 3};
    cout << "Test 1 Output: " << sol.minOperations(nums1, target1) << endl;

    // Test Case 2
    vector<int> nums2 = {4, 1, 4};
    vector<int> target2 = {5, 1, 4};
    cout << "Test 2 Output: " << sol.minOperations(nums2, target2) << endl;

    // Test Case 3
    vector<int> nums3 = {7, 3, 7};
    vector<int> target3 = {5, 5, 9};
    cout << "Test 3 Output: " << sol.minOperations(nums3, target3) << endl;

    return 0;
}
