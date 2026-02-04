#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseByType(string s) {

        int n = s.length(); 

        int i = 0; 
        int j = n - 1; 

        while (i <= j) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (isalpha(s[i]))
                j--;
            else
                i++;
        }

        i = 0; 
        j = n - 1; 

        while (i <= j) {
            if (!isalpha(s[i]) && !isalpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!isalpha(s[i]))
                j--;
            else
                i++;
        }

        return s; 
    }
};

int main() {
    Solution sol;

    // Hardcoded test cases
    vector<string> testCases = {
        ")ebc#da@f(",
        "z",
        "!@#$%^&*()"
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Input:  " << testCases[i] << endl;
        cout << "Output: " << sol.reverseByType(testCases[i]) << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}
