#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
    
        int leftCountOne = 0 ; 
        int rightCountZero = 0  ;

        for(char &ch : s)
        if(ch == '0' )rightCountZero ++ ; 

        int result = rightCountZero ; 

        for(char &ch : s) {

            if(ch == '0') rightCountZero -- ; 
            else leftCountOne ++ ; 


            result = min(result , leftCountOne + rightCountZero) ; 
        }

        return result ; 

    }
};

int main() {
    Solution sol;

    // Hard-coded test cases
    vector<string> testCases = {
        "00110",
        "010110",
        "00011000"
    };

    for (string s : testCases) {
        cout << "Input: " << s << endl;
        cout << "Output: " << sol.minFlipsMonoIncr(s) << endl;
        cout << "----------------------" << endl;
    }

    return 0;
}
