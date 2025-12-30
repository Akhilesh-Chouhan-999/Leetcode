#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        int n = nums.size();

        vector<int> minElement(n, 0);
        minElement[n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--) {
            minElement[i] = min(minElement[i + 1], nums[i]);
        }

        long long sum = 0;
        long long result = LLONG_MIN;

        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            result = max(result, sum - minElement[i + 1]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {5, 2, 4, 6, 3};
    cout << "Output 1: " << sol.maximumScore(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Output 2: " << sol.maximumScore(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {-5, -2, -3, -1};
    cout << "Output 3: " << sol.maximumScore(nums3) << endl;

    return 0;
}
