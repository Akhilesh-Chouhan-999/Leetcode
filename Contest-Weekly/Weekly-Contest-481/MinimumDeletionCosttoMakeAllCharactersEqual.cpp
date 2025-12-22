#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        int n = s.length(); 
        vector<long long> mpp(26, 0); 
        long long sum = 0; 
        
        for (int i = 0; i < n; i++) {
            mpp[s[i] - 'a'] += cost[i];  
        }

        long long maxi = LLONG_MIN; 
        
        for (int i = 0; i < 26; i++) {
            sum += mpp[i]; 
            maxi = max(maxi, mpp[i]); 
        }

        return sum - maxi; 
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    string s = "aba";
    vector<int> cost = {1, 2, 3};

    cout << "Input string: " << s << "\n";
    cout << "Cost array: ";
    for (int c : cost) cout << c << " ";
    cout << "\n";

    cout << "Output: " << sol.minCost(s, cost) << "\n";

    return 0;
}
