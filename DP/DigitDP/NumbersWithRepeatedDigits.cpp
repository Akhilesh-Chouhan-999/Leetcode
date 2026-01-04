#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[11][2][1024][2][2]; 
    
    int solve(string &num , int index , bool tight , int mask , int leadZeros , bool repeated ){

          if(index >= num.size() )
          return repeated ; 


          if(dp[index][tight][mask][leadZeros][repeated] != -1)
          return dp[index][tight][mask][leadZeros][repeated] ;

          int upperBound = tight  ? num[index] - '0' : 9 ; 

          int ans = 0 ; 

          for(int dig = 0 ; dig <= upperBound ; dig ++ ){

               bool newLeadZeros = leadZeros && (dig == 0) ; 
               bool newTight = tight && dig == upperBound ; 

               if(newLeadZeros){
                  ans +=  solve(num , index + 1 , newTight , mask , newLeadZeros , repeated) ; 
               }else{

                    bool newRepeated = repeated;
                    int newMask = mask;

                    if(newMask & (1 << dig)) 
                    newRepeated = true;
                    newMask |= (1 << dig);


                  ans +=   solve(num , index + 1 , newTight , newMask , newLeadZeros , newRepeated ) ; 
               }
          }

          return dp[index][tight][mask][leadZeros][repeated] = ans ; 

    }

    int numDupDigitsAtMostN(int n) {

     memset(dp , -1 , sizeof dp) ; 
     string num = to_string(n)  ; 
     return solve(num , 0 , 1 , 0 , 1 , 0 ) ; 
        
    }
};

int main() {
    Solution sol;

    int n1 = 20;
    int n2 = 100;
    int n3 = 1000;
    int n4 = 1;
    int n5 = 9;
    int n6 = 11;

    cout << "Input: " << n1 << " Output: " << sol.numDupDigitsAtMostN(n1)
         << " Expected: 1" << endl;   // 11

    cout << "Input: " << n2 << " Output: " << sol.numDupDigitsAtMostN(n2)
         << " Expected: 10" << endl;  // 11,22,33,44,55,66,77,88,99,100

    cout << "Input: " << n3 << " Output: " << sol.numDupDigitsAtMostN(n3)
         << " Expected: 262" << endl;

    cout << "Input: " << n4 << " Output: " << sol.numDupDigitsAtMostN(n4)
         << " Expected: 0" << endl;

    cout << "Input: " << n5 << " Output: " << sol.numDupDigitsAtMostN(n5)
         << " Expected: 0" << endl;

    cout << "Input: " << n6 << " Output: " << sol.numDupDigitsAtMostN(n6)
         << " Expected: 1" << endl;   // 11

    return 0;
}

/*

Time Complexity : 
(number of states) × (work per state)
= 90,112 × 10
≈ 900,000
≈ O(10^6)

Space Complexity : 
11 × 2 × 1024 × 2 × 2
= O(10^5)

*/