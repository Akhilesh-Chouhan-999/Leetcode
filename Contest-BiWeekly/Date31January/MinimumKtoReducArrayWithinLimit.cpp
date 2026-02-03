#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumK(vector<int>& nums) {
       
        int n = nums.size() ;

                                                                
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 7, 5},
        {1},
        {10, 10, 10},
        {100000}
    };

    for (auto &nums : testCases) {
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << endl;

        cout << "Minimum k: " << sol.minimumK(nums) << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
