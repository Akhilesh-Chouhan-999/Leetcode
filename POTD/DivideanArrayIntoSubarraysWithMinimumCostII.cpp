#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        
    }
} ; 

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 3, 2, 6, 4, 2};
    int k1 = 3, dist1 = 3;
    cout << sol.minimumCost(nums1, k1, dist1) << endl; // Expected: 5

    // Test case 2
    vector<int> nums2 = {10, 1, 2, 2, 2, 1};
    int k2 = 4, dist2 = 3;
    cout << sol.minimumCost(nums2, k2, dist2) << endl; // Expected: 15

    // Test case 3
    vector<int> nums3 = {10, 8, 18, 9};
    int k3 = 3, dist3 = 1;
    cout << sol.minimumCost(nums3, k3, dist3) << endl; // Expected: 36

    return 0;
}
