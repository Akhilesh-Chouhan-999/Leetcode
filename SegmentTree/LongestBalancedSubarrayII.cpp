#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums){
        
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 5, 4, 3};
    cout << "Output: " << sol.longestBalanced(nums1)
         << " | Expected: 4" << endl;

    // Example 2
    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << "Output: " << sol.longestBalanced(nums2)
         << " | Expected: 5" << endl;

    // Example 3
    vector<int> nums3 = {1, 2, 3, 2};
    cout << "Output: " << sol.longestBalanced(nums3)
         << " | Expected: 3" << endl;

    return 0;
}
