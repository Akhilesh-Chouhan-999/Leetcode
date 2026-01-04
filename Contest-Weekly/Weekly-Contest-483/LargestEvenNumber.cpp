#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestEven(string s) {
        
        int n = s.length() ; 

        int idx = n - 1 ; 

        while(idx >= 0 && s[idx--] == '1')
        s.pop_back() ; 


        return s;
    }
};

int main() {
    Solution sol;

    vector<string> testCases = {
        "1112",
        "221",
        "1"
    };

    for (string s : testCases) {
        cout << "Input: " << s << endl;
        cout << "Output: " << sol.largestEven(s) << endl;
        cout << "--------------------" << endl;
    }

    return 0;
}
