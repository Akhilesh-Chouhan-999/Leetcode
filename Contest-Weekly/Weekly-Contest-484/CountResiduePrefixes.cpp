#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int residuePrefixes(string s) {

        int n = s.length() ;
        unordered_map<char , int>freq ;
        int result = 0  ; 

        for(int i = 0 ; i < n ; i ++ ){
            freq[s[i] ] ++ ; 

            if(freq.size() == (i + 1) % 3){
                result ++ ;  
            }

        }

        return result ; 

    }
};

int main() {
    Solution sol;

    // Hardcoded Test Cases
    vector<string> testCases = {
        "abc",
        "dd",
        "bob",
        "a",
        "aaa",
        "abca"
    };

    vector<int> expected = {
        2,  // "abc"
        1,  // "dd"
        2,  // "bob"
        1,  // "a"
        1,  // "aaa"
        2   // "abca"
    };

     for (int i = 0; i < testCases.size(); i++) {
        int result = sol.residuePrefixes(testCases[i]);
        cout << "Input: \"" << testCases[i] << "\"\n";
        cout << "Output: " << result << "\n";
        cout << "Expected: " << expected[i] << "\n";
       
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(26) => O(1)