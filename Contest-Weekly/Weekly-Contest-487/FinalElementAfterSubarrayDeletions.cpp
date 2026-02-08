#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0], nums.back());
    }
};

int main() {
    Solution sol;

    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {1, 5, 2},      // Expected: 2
        {3, 7},         // Expected: 7
        {4},            // Expected: 4
        {10, 1, 8, 6},  // Expected: 10
        {5, 2, 9}       // Expected: 9
    };

    vector<int> expected = {2, 7, 4, 10, 9};

    for (int i = 0; i < testCases.size(); i++) {
        vector<int>& nums = testCases[i];

        cout << "nums = [ ";
        for (int x : nums) cout << x << " ";
        cout << "] ";

        int result = sol.finalElement(nums);

        cout << "Output = " << result
             << ", Expected = " << expected[i];

             cout << endl;

    }

    return 0;
}
