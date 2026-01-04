#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
   int solve(vector<string>&digits , int index , bool tight , bool leadingZeros , string N) {

     if(index == N.size()){
        return leadingZeros == false ; 
     }


     int upperBound = tight ? N[index] - '0' : 9 ; 
     
     int ans = 0 ; 

     for(int i = 0 ; i < digits.size() ; i ++ ){

        int d = digits[i][0] - '0' ; 

        if( d > upperBound) 
        continue;

        bool newTight = tight && d == upperBound ;

        bool newLeadingZeros = leadingZeros && d == 0 ; 

        if(newLeadingZeros){
            ans += solve(digits , index +1 , newTight , newLeadingZeros , N) ; 
        }else{
            ans += solve(digits ,index + 1 , newTight , newLeadingZeros , N ) ; 
        }

     }

     return ans ; 


   }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        string N = to_string(n) ; 


    }
};

int main() {
    Solution sol;


    vector<string> digits1 = {"1","3","5","7"};
    int n1 = 100;
    cout << "Output (Example 1): "
         << sol.atMostNGivenDigitSet(digits1, n1)
         << " | Expected: 20" << endl;

    vector<string> digits2 = {"1","4","9"};
    int n2 = 1000000000;
    cout << "Output (Example 2): "
         << sol.atMostNGivenDigitSet(digits2, n2)
         << " | Expected: 29523" << endl;

    vector<string> digits3 = {"7"};
    int n3 = 8;
    cout << "Output (Example 3): "
         << sol.atMostNGivenDigitSet(digits3, n3)
         << " | Expected: 1" << endl;

    return 0;
}
