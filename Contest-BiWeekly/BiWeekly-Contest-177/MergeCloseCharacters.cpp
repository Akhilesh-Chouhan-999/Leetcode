#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k){

        int n = s.length() ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "abca";
    int k1 = 3;
    cout << "Output: " << sol.mergeCharacters(s1, k1)
         << " | Expected: abc" << endl;

    // Example 2
    string s2 = "aabca";
    int k2 = 2;
    cout << "Output: " << sol.mergeCharacters(s2, k2)
         << " | Expected: abca" << endl;

    // Example 3
    string s3 = "yybyzybz";
    int k3 = 2;
    cout << "Output: " << sol.mergeCharacters(s3, k3)
         << " | Expected: ybzybz" << endl;

    return 0;
}