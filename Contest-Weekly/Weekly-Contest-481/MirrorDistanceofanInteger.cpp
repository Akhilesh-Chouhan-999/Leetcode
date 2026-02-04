#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        long long rev = 0;
        int temp = n;
        
        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }
        
        return abs(n - (int)rev);
    }
};

int main() {
    Solution sol;

    // Hardcoded test cases
    vector<int> testCases = {25, 10, 7};

    cout << "Mirror Distance Results:\n\n";

    for (int n : testCases) {
        cout << "Input: n = " << n << "\n";
        cout << "Output: " << sol.mirrorDistance(n) << "\n\n";
    }

    return 0;
}

// Time Complexity : O(d) where d is the digit in the number . 
// Space Complexity : O(1)