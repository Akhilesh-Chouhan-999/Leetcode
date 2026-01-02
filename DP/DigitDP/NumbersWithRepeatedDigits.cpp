#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10][2][10][2] ; 
    
    int numDupDigitsAtMostN(int n) {
        
    }
};

int main() {
    Solution sol;

    int n1 = 20;
    int n2 = 100;
    int n3 = 1000;
    int n4 = 1;
    int n5 = 9;
    int n6 = 11;

    cout << "Input: " << n1 << " Output: " << sol.numDupDigitsAtMostN(n1)
         << " Expected: 1" << endl;   // 11

    cout << "Input: " << n2 << " Output: " << sol.numDupDigitsAtMostN(n2)
         << " Expected: 10" << endl;  // 11,22,33,44,55,66,77,88,99,100

    cout << "Input: " << n3 << " Output: " << sol.numDupDigitsAtMostN(n3)
         << " Expected: 262" << endl;

    cout << "Input: " << n4 << " Output: " << sol.numDupDigitsAtMostN(n4)
         << " Expected: 0" << endl;

    cout << "Input: " << n5 << " Output: " << sol.numDupDigitsAtMostN(n5)
         << " Expected: 0" << endl;

    cout << "Input: " << n6 << " Output: " << sol.numDupDigitsAtMostN(n6)
         << " Expected: 1" << endl;   // 11

    return 0;
}
