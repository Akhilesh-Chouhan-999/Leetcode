/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>memo ; 

    int solve(vector<int>&pfsq , int n , int idx  ){

        if( n == 0)
        return 0 ; 

        if(idx >= pfsq.size() || n < 0 )
        return 1e9 ;


        if(memo[n][idx] != -1)
        return memo[n][idx] ; 

        int take = 1 + solve(pfsq , n - pfsq[idx] , idx   ) ; 
        int skip = solve(pfsq , n , idx + 1  ) ; 


        return memo[n][idx] =  min(take , skip) ; 

    }

    int numSquares(int n) {


        vector<int>pfSq ; 

        for(int i = 1 ; i*i <= n ; i ++ ){
            pfSq.push_back(i*i) ; 
        }

        memo.resize( n + 1 , vector<int>(pfSq.size() + 1 , -1)) ; 


        return solve(pfSq , n , 0  ) ; 

    }
};

int main() {
    Solution sol;

    int n1 = 12;
    int n2 = 13;
    int n3 = 1;
    int n4 = 100;
    int n5 = 9999;

    cout << "Input: " << n1 << " -> Output: " << sol.numSquares(n1) << endl;
    cout << "Input: " << n2 << " -> Output: " << sol.numSquares(n2) << endl;
    cout << "Input: " << n3 << " -> Output: " << sol.numSquares(n3) << endl;
    cout << "Input: " << n4 << " -> Output: " << sol.numSquares(n4) << endl;
    cout << "Input: " << n5 << " -> Output: " << sol.numSquares(n5) << endl;

    return 0;
}


// Time Complexity : O( n * root(n))
// Space Complexity : O(n * root(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numSquares(int n) {

    }
};

int main() {
    Solution sol;

    int n1 = 12;
    int n2 = 13;
    int n3 = 1;
    int n4 = 100;
    int n5 = 9999;

    cout << "Input: " << n1 << " -> Output: " << sol.numSquares(n1) << endl;
    cout << "Input: " << n2 << " -> Output: " << sol.numSquares(n2) << endl;
    cout << "Input: " << n3 << " -> Output: " << sol.numSquares(n3) << endl;
    cout << "Input: " << n4 << " -> Output: " << sol.numSquares(n4) << endl;
    cout << "Input: " << n5 << " -> Output: " << sol.numSquares(n5) << endl;

    return 0;
}


// Time Complexity : O( n * root(n))
// Space Complexity : O(n * root(n))