#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        // your implementation goes here
        return 0;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> numsTestCases = {
        {2, 1, 5, 2, 3},
        {4, 7, 2, 9}
    };

    vector<string> sTestCases = {
        "01010",
        "0000"
    };

    vector<long long> expectedOutput = {
        7,
        0
    };

    for (int i = 0; i < numsTestCases.size(); i++) {
        long long result = sol.maximumScore(numsTestCases[i], sTestCases[i]);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expectedOutput[i] << endl;
    }

    return 0;
}
