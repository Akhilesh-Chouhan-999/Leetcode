/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int cntWays(char ch, int len, int n) {

        if (len == n) return 1;

        int ways = 0;   

        if (ch <= 'a') {
            ways += cntWays('a', len + 1, n);
        }

        if (ch <= 'e') {
            ways += cntWays('e', len + 1, n);
        }

        if (ch <= 'i') {
            ways += cntWays('i', len + 1, n);
        }

        if (ch <= 'o') {
            ways += cntWays('o', len + 1, n);
        }

        if (ch <= 'u') {
            ways += cntWays('u', len + 1, n);
        }

        return ways;
    }

    int countVowelStrings(int n){

        int ans1 = cntWays('a', 1, n);
        int ans2 = cntWays('e', 1, n);
        int ans3 = cntWays('i', 1, n);
        int ans4 = cntWays('o', 1, n);
        int ans5 = cntWays('u', 1, n);

        return ans1 + ans2 + ans3 + ans4 + ans5;
    }
};


int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.countVowelStrings(1)
         << " | Expected: 5" << endl;

    // Example 2
    cout << "Output: " << sol.countVowelStrings(2)
         << " | Expected: 15" << endl;

    // Example 3
    cout << "Output: " << sol.countVowelStrings(33)
         << " | Expected: 66045" << endl;

    return 0;
}

// Time Complexity : O(5 ^ n)
// Space Complexity : O(n)


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int dp[51][5] ; 

    int getIndex(char ch){
        
        if (ch == 'a') return 0;
        if (ch == 'e') return 1;
        if (ch == 'i') return 2;
        if (ch == 'o') return 3;
        return 4;
    }

    int cntWays(char ch, int len, int n) {

        if (len == n) return 1;

        int index = getIndex(ch) ; 

        if(dp[len][index] != -1)
        return dp[len][index] ; 

        int ways = 0;   

        if (ch <= 'a') {
            ways += cntWays('a', len + 1, n);
        }

        if (ch <= 'e') {
            ways += cntWays('e', len + 1, n);
        }

        if (ch <= 'i') {
            ways += cntWays('i', len + 1, n);
        }

        if (ch <= 'o') {
            ways += cntWays('o', len + 1, n);
        }

        if (ch <= 'u') {
            ways += cntWays('u', len + 1, n);
        }

        return dp[len][index] =  ways;
    }

    int countVowelStrings(int n){

        memset(dp , -1 , sizeof(dp)) ; 

        int ans1 = cntWays('a', 1, n);
        int ans2 = cntWays('e', 1, n);
        int ans3 = cntWays('i', 1, n);
        int ans4 = cntWays('o', 1, n);
        int ans5 = cntWays('u', 1, n);

        return ans1 + ans2 + ans3 + ans4 + ans5;
    }
};


int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.countVowelStrings(1)
         << " | Expected: 5" << endl;

    // Example 2
    cout << "Output: " << sol.countVowelStrings(2)
         << " | Expected: 15" << endl;

    // Example 3
    cout << "Output: " << sol.countVowelStrings(33)
         << " | Expected: 66045" << endl;

    return 0;
}

// Time Complexity : O(5 * n)
// Space Complexity : O(n)




#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int dp[51][5] ;

    int solve(int len , int idx , int n ){

        if(len == n)
        return 1 ; 

        if(dp[len][idx] != -1) 
        return dp[len][idx]  ;

        int ways = 0 ; 

        for(int next = idx ; next < 5 ; next ++ ){
            ways += solve(len + 1 , next , n) ;
        }

        return  dp[len][idx] =  ways ; 
    }

    int countVowelStrings(int n){

        int result = 0 ; 
        memset(dp , -1 , sizeof(dp)) ;

        for(int i = 0 ; i < 5 ; i ++ ){
            result += solve(1 , i , n ) ;
        }

        return result ; 
    }
};


int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.countVowelStrings(1)
         << " | Expected: 5" << endl;

    // Example 2
    cout << "Output: " << sol.countVowelStrings(2)
         << " | Expected: 15" << endl;

    // Example 3
    cout << "Output: " << sol.countVowelStrings(33)
         << " | Expected: 66045" << endl;

    return 0;
}

Time Complexity : O(5 * n)
Space Complexity : O(n * 5)

*/




#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    
    int countVowelStrings(int n){

        vector<vector<int>>dp( n + 1 , vector<int>(5 , 0 )) ;

        for(int i = 0 ; i < 5 ; i ++ ) 
        dp[1][i] = 1 ;
        
        for(int len = 2 ; len <= n ; len ++ ){

            for(int idx = 4 ; idx >= 0 ; idx -- ){
                    dp[len][idx]  = dp[len - 1][idx] ; 

                    if(idx + 1 < 5 ){
                        dp[len][idx] += dp[len][idx+1] ; 
                    }

            }
        }


        int result = 0 ; 

        for(int i = 0 ; i < 5 ; i ++ ){
            result +=  dp[n][i]  ;
        }

        return result ; 

    }
};


int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.countVowelStrings(1)
         << " | Expected: 5" << endl;

    // Example 2
    cout << "Output: " << sol.countVowelStrings(2)
         << " | Expected: 15" << endl;

    // Example 3
    cout << "Output: " << sol.countVowelStrings(33)
         << " | Expected: 66045" << endl;

    return 0;
}

// dp[i][j] = Number of valid strings of length i where the first character is vowel j or greater

// Time complexity : O(5*n)
// Time complexity : O(n)

