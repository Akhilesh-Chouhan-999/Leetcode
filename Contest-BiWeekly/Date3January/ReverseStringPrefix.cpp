#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string s, int k) {

        int i = 0 ; 
        int j = k - 1 ; 

        while ( i <= j){
           swap(s[i] , s[j]) ; 
           i ++ ; 
           j -- ; 
        }

        return s ; 

        // Inbuilt function 
        // reverse(s.begin() , s.end()  - k ) ; 
        
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "abcd";
    int k1 = 2;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << sol.reversePrefix(s1, k1) << endl;
    cout << "Expected: bacd\n" << endl;

    // Test case 2
    string s2 = "xyz";
    int k2 = 3;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << sol.reversePrefix(s2, k2) << endl;
    cout << "Expected: zyx\n" << endl;

    // Test case 3
    string s3 = "hey";
    int k3 = 1;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output: " << sol.reversePrefix(s3, k3) << endl;
    cout << "Expected: hey\n" << endl;

    return 0;
}


// Time Complexity : O(k) 
// Space Complexity : O(1)