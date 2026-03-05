#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int target ;
    int memo[1001][1001] ;

    int solve(int n , int length){

        if(n == target)
        return 0 ; 

        if( n > target)
        return INT_MAX ; 

        if(memo[n][length] != -1)
        return memo[n][length]  ;

        int copyAndPaste = solve(2*n , n) ; 

        if(copyAndPaste != INT_MAX) 
        copyAndPaste += 2 ; 

        int pasteOnly = INT_MAX ;

         if(length != 0){
            pasteOnly = solve(n + length , length) ; 
            if(pasteOnly != INT_MAX)
            pasteOnly += 1 ; 
         }


         return memo[n][length] = min(copyAndPaste , pasteOnly) ; 

    }
    int minSteps(int n){

        target = n ; 

        memset(memo , -1 , sizeof(memo) ) ; 

        return solve(1 , 0) ; 

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
    cout << "Output: " << sol.minSteps(6)
         << " | Expected: 5" << endl;

    return 0;
}

// Time complexity : O(n * length)
// Space Complexity : O(n*length)