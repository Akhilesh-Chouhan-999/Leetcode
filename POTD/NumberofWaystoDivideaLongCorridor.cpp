#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numberOfWays(string corridor) {
        
        
        
    }
};

int main() {
    Solution obj;

    
    vector<pair<string, int>> tests = {
        {"SSPPSPS", 3},
        {"PPSPSP", 1},
        {"S", 0},
        {"SSPPSS", 1},
        {"SPPSPSPPS", 2}
    };

    for (auto &test : tests) {
        string corridor = test.first;
        int expected = test.second;

        int result = obj.numberOfWays(corridor);

        cout << "Corridor        : " << corridor << endl;
        cout << "Expected Output : " << expected << endl;
        cout << "Your Output     : " << result << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}
