#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSequences(vector<int>& nums, long long k){

        int n = nums.size() ;

        
    }
};


int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 3, 2};
    long long k1 = 6;
    cout << "Output: " << sol.countSequences(nums1, k1)
         << " | Expected: 2" << endl;

    // Example 2
    vector<int> nums2 = {4, 6, 3};
    long long k2 = 2;
    cout << "Output: " << sol.countSequences(nums2, k2)
         << " | Expected: 2" << endl;

    // Example 3
    vector<int> nums3 = {1, 5};
    long long k3 = 1;
    cout << "Output: " << sol.countSequences(nums3, k3)
         << " | Expected: 3" << endl;

    return 0;
}