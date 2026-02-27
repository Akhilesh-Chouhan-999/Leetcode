/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n ; 

    int calculateWays(string s , int i ){

        if( i == n )
        return 1 ;

        if(s[i] == '0')
        return 0 ; 


        int ways = 0 ; 

        ways += calculateWays(s , i + 1 ) ; 

        if( i + 1 < n ){

            int num = ( s[i] - '0' ) * 10  + ( s[i + 1]  - '0' ) ;

            if(num >= 1 && num <= 26 ){
              ways += calculateWays(s , i  + 2 ) ; 
            }
 
        }

        return ways ; 
    }


    int numDecodings(string s) {
        
        n = s.length() ; 

      return  calculateWays(s , 0  ) ; 


    }
};


int main() {
    Solution sol;

    // ---------- Example 1 ----------
    string s1 = "12";
    cout << "Output: " << sol.numDecodings(s1)
         << " | Expected: 2" << endl;

    // ---------- Example 2 ----------
    string s2 = "226";
    cout << "Output: " << sol.numDecodings(s2)
         << " | Expected: 3" << endl;

    // ---------- Example 3 ----------
    string s3 = "06";
    cout << "Output: " << sol.numDecodings(s3)
         << " | Expected: 0" << endl;

    // ---------- Additional edge case ----------
    string s4 = "11106";
    cout << "Output: " << sol.numDecodings(s4)
         << " | Expected: 2" << endl;

    return 0;
}

// Time Complexity : O( 2 ^ n )
// Space Complexity : O( n )




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n ; 
    vector<int>dp ; 

    // dp[i] : Total no. of ways to decode the string from i th index  

    int calculateWays(string s , int i ){

        if( i == n )
        return 1 ;

        if(s[i] == '0')
        return 0 ; 


        if(dp[i] != -1)
        return dp[i] ; 


        int ways = 0 ; 

        ways += calculateWays(s , i + 1 ) ; 

        if( i + 1 < n ){

            int num = ( s[i] - '0' ) * 10  + ( s[i + 1]  - '0' ) ;

            if(num >= 10 && num <= 26 ){
              ways += calculateWays(s , i  + 2 ) ; 
            }
 
        }

        return dp[i] =  ways ; 
    }


    int numDecodings(string s) {
        
        n = s.length() ; 
        dp.resize( n , -1) ; 

      return  calculateWays(s , 0  ) ; 

    }
};


int main() {
    Solution sol;

    // ---------- Example 1 ----------
    string s1 = "12";
    cout << "Output: " << sol.numDecodings(s1)
         << " | Expected: 2" << endl;

    // ---------- Example 2 ----------
    string s2 = "226";
    cout << "Output: " << sol.numDecodings(s2)
         << " | Expected: 3" << endl;

    // ---------- Example 3 ----------
    string s3 = "06";
    cout << "Output: " << sol.numDecodings(s3)
         << " | Expected: 0" << endl;

    // ---------- Additional edge case ----------
    string s4 = "11106";
    cout << "Output: " << sol.numDecodings(s4)
         << " | Expected: 2" << endl;

    return 0;
}

// Time Complexity : O( n )
// Space Complexity : O( n )

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numDecodings(string s) {
       
        int n = s.length() ; 

        vector<int>dp(n , 0 ) ; 

        dp[n-1] = 1 ; 

        for(int i = n - 2  ; i >= 0 ; i -- ){

            int num = (s[i] - '0') * 10 + ( s[i+1] - '0')  ; 


            if(s[i] == 0) {
                dp[i] = dp[i+1] ; 
            }
            else if(num >= 1 && num <= 26 ){
                dp[i] = dp[i+1] + 1 ; 
            }

        }

        return dp[0] ; 
    }
};


int main() {
    Solution sol;

    // ---------- Example 1 ----------
    string s1 = "12";
    cout << "Output: " << sol.numDecodings(s1)
         << " | Expected: 2" << endl;

    // ---------- Example 2 ----------
    string s2 = "226";
    cout << "Output: " << sol.numDecodings(s2)
         << " | Expected: 3" << endl;

    // ---------- Example 3 ----------
    string s3 = "06";
    cout << "Output: " << sol.numDecodings(s3)
         << " | Expected: 0" << endl;

    // ---------- Additional edge case ----------
    string s4 = "11106";
    cout << "Output: " << sol.numDecodings(s4)
         << " | Expected: 2" << endl;

    return 0;
}

// Time Complexity : O( n )
// Space Complexity : O( n )