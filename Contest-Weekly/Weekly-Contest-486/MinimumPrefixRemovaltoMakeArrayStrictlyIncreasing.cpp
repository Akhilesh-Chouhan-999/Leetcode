#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int n = nums.size() ; 

        int index = -1 ; 

        for(int i = n - 2 ; i >= 0 ; i --){
            if(nums[i] >= nums[i+1]){
                index = i ; 
                break ; 
            }
        }

        return index == -1 ? 0 : index + 1 ; 
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, -1, 2, 3, 3, 4, 5};
    cout << "Output 1: " << sol.minimumPrefixLength(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {4, 3, -2, -5};
    cout << "Output 2: " << sol.minimumPrefixLength(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Output 3: " << sol.minimumPrefixLength(nums3) << endl;

    return 0;
}
