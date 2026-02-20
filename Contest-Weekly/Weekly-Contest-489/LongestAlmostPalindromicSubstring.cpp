#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int almostPalindromic(string s){

        int n = s.length() ; 

        
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "abca";
    cout << "Output: " << sol.almostPalindromic(s1)
         << " | Expected: 4" << endl;

    // Example 2
    string s2 = "abba";
    cout << "Output: " << sol.almostPalindromic(s2)
         << " | Expected: 4" << endl;

    // Example 3
    string s3 = "zzabba";
    cout << "Output: " << sol.almostPalindromic(s3)
         << " | Expected: 5" << endl;

    return 0;
}