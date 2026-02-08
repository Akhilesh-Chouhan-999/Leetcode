#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        // Logic not implemented
        return 0;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {2, 1, 3, 2};
    // Expected Output: 4

    vector<int> test2 = {3, 2, 1, 2, 3, 2, 1};
    // Expected Output: 4

    vector<int> test3 = {100000, 100000};
    // Expected Output: 1

    cout << "Test Case 1 Output: " << sol.longestAlternating(test1) << endl;
    cout << "Test Case 2 Output: " << sol.longestAlternating(test2) << endl;
    cout << "Test Case 3 Output: " << sol.longestAlternating(test3) << endl;

    return 0;
}
