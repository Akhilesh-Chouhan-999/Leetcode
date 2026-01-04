#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[11][2][1024][2]; 
    
    int solve(string &num , int index , bool tight , int mask , bool leadZeros  ){

     if(index == num.size()){
          return 1 ; 
     }

     if(dp[index][tight][mask][leadZeros] != -1)
     return dp[index][tight][mask][leadZeros] ; 

     int upperBound = tight ? num[index] -'0' : 9 ;

     int countUnique = 0 ; 

     for(int dig = 0 ; dig <= upperBound ; dig ++ ){

          bool newTight = tight && (dig == upperBound) ; 
          bool newLeadZeros = leadZeros && (dig == 0) ; 

          if(newLeadZeros){
               countUnique += solve(num , index + 1 , newTight , mask , newLeadZeros ) ;
          }else{
               if(mask & ( 1 << dig)){
                    continue;  
               }

               int newMask = mask | ( 1 << dig)  ; 

                countUnique +=  solve(num , index + 1 , newTight , newMask , newLeadZeros) ; 

          }

          
     }

     return  dp[index][tight][mask][leadZeros] = countUnique ; 
       

    }

    int numDupDigitsAtMostN(int n) {

     memset(dp , -1 , sizeof dp) ; 
     string num = to_string(n)  ; 
     int unique =  solve(num , 0 , 1 , 0 , 1 ) ; 

     return n - (unique - 1) ; 
        
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

// TC = number of states × work per state
//    = 45,056 × 10
//    ≈ 450,000
//    ≈ O(10^5)
// SC : 11 × 2 × 1024 × 2 = 45,056 integers
//                 Stack space ≈ O(11) ≈ constant

