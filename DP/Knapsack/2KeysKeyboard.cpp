#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int target ; 

   int solve(int n ){

    if( n  == target )
    return 0 ; 

    if( n > target)
    return INT_MAX ; 

    int copy = n ; 

    int copyAndPaste = INT_MAX ;
    int paste = INT_MAX ; 

    if(solve(n + copy) != INT_MAX)
    copyAndPaste = 2 + solve(n + copy) ; 

    if(solve(copy + n ) != INT_MAX)
    paste = 1 + solve(copy + n ) ; 


    return min( copyAndPaste  , paste ) ; 

   }
    int minSteps(int n){

        target = n ; 

        return solve(1) ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.minSteps(3)
         << " | Expected: 3" << endl;

    // Example 2
    cout << "Output: " << sol.minSteps(1)
         << " | Expected: 0" << endl;

    // Additional test
    cout << "Output: " << sol.minSteps(5)
         << " | Expected: 5" << endl;

    return 0;
}