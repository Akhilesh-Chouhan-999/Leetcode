#include <bits/stdc++.h>
using namespace std;

    static int memo[601][101][101] ;
class Solution {
public:



    int countZeros(string &s ){

        int cnt = 0 ; 

        for(char ch : s){
            if(ch == '0') cnt ++ ;
        }

        return cnt ; 
    }

    int solve(vector<string>&strs , int idx , int m , int n ){

        if(idx >= strs.size())
        return 0 ; 


        if(memo[idx][m][n] != -1)
        return memo[idx][m][n] ; 
        
        int cntZero = countZeros(strs[idx]) ; 
        int cntOne = strs[idx].size() - cntZero ; 
        
        int take = INT_MIN ; 
        if(cntZero <= m && cntOne <= n)
        take = 1 + solve(strs , idx + 1 , m - cntZero   , n  - cntOne) ; 

        int skip = solve(strs , idx + 1 , m , n) ; 

        if(take == INT_MIN)
        take = 0 ; 

        return  memo[idx][m][n] = max(take , skip) ; 

    }


    int findMaxForm(vector<string>& strs, int m, int n){

        memset(memo  , -1 , sizeof(memo)) ; 

        return solve(strs , 0 , m , n) ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<string> strs1 = {"10","0001","111001","1","0"};
    int m1 = 5, n1 = 3;
    cout << "Output: " << sol.findMaxForm(strs1, m1, n1)
         << " | Expected: 4" << endl;

    // Example 2
    vector<string> strs2 = {"10","0","1"};
    int m2 = 1, n2 = 1;
    cout << "Output: " << sol.findMaxForm(strs2, m2, n2)
         << " | Expected: 2" << endl;

    return 0;
}


// Time Compleixty : O(k × M × N * L )  Where k = strs.size() , M = m , N = n , L = Average length of str[i]  asdfjk ;
// Space Complexity :  O(k × M × N ) 