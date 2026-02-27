#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s){

        int value = stoi(s, nullptr, 2);

        int opern = 0 ; 

        while (value != 1){

            if(value % 2 == 0 ){
                value /= 2 ; 
            }
            else{
                value += 1 ; 
            }

            opern ++ ; 
        }

        return opern ; 
        
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "1101";
    cout << "Output: " << sol.numSteps(s1)
         << " | Expected: 6" << endl;

    // Example 2
    string s2 = "10";
    cout << "Output: " << sol.numSteps(s2)
         << " | Expected: 1" << endl;

    // Example 3
    string s3 = "1";
    cout << "Output: " << sol.numSteps(s3)
         << " | Expected: 0" << endl;

    return 0;
}