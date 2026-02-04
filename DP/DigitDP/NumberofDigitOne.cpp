#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
     int dp[11][2][11] ; 

    int solve(string &num ,  int index , bool tight  , int countOne ) {

        if(index == num.size()){
            return countOne ; 
        }

        if(dp[index][tight][countOne] != -1){
            return dp[index][tight][countOne] ; 
        }


        int upperBound =   tight ? num[index] - '0' : 9 ; 

        int ans = 0 ; 

        for(int i = 0 ; i <= upperBound ; i ++ ){

           int newCountOne = countOne + ( i == 1 );
           int newTight = tight && ( i == upperBound) ; 

           ans +=  solve(num  , index + 1 , newTight , newCountOne  ) ; 

        }

        return  dp[index][tight][countOne] = ans ;    

    }


    int countDigitOne(int n) {

        memset(dp , -1 , sizeof dp) ; 

        string num = to_string(n) ; 

        return solve(num , 0 , true , 0) ; 

       
    }
};

int main() {
    Solution sol;

    // Test cases
    int n1 = 13;
    int n2 = 0;
    int n3 = 100;
    int n4 = 1;

    cout << "Input: " << n1 << " Output: " << sol.countDigitOne(n1) << " Expected: 6 " << endl;  // Expected: 6
    cout << "Input: " << n2 << " Output: " << sol.countDigitOne(n2) << " Expected: 0 " << endl;  // Expected: 0
    cout << "Input: " << n3 << " Output: " << sol.countDigitOne(n3) << " Expected: 21" << endl;  // Expected: 21
    cout << "Input: " << n4 << " Output: " << sol.countDigitOne(n4) << " Expected: 1 " << endl;  // Expected: 1

    return 0;
}




   /*
   TC = (number of states) × (work per state)
   = (10 × 2 × 10) × 10
   = ( d * 2 * d ) * 10 (for iteration over 0 to 9)
   = 2000

   SC =
   d × 2 × d = 2d²

   */