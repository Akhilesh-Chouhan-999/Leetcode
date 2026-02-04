#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int solve(int i , int j , string &s1 , string &s2 , int cost){


    }

    int minimumDeleteSum(string s1, string s2) {
        
        
    }
};
int main() {
    Solution sol;

    // Test Case 1
    string s1 = "sea";
    string s2 = "eat";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.minimumDeleteSum(s1, s2) << endl;
    cout << "Expected Output: 231\n" << endl;

    // Test Case 2
    s1 = "delete";
    s2 = "leet";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.minimumDeleteSum(s1, s2) << endl;
    cout << "Expected Output: 403\n" << endl;

    // Test Case 3 (both same)
    s1 = "abc";
    s2 = "abc";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.minimumDeleteSum(s1, s2) << endl;
    cout << "Expected Output: 0\n" << endl;

    // Test Case 4 (one empty)
    s1 = "";
    s2 = "abc";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.minimumDeleteSum(s1, s2) << endl;
    cout << "Expected Output: 294\n" << endl;

    return 0;
}
