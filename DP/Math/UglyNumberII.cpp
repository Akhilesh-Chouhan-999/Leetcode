/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    bool checkUglyNumber(int num ){

        while(num % 2 == 0) num /= 2 ; 
        while(num % 3 == 0) num /= 3 ; 
        while(num % 5 == 0) num /= 5 ; 


        return num == 1 ;
    }
  
    int nthUglyNumber(int n){

        
        int count = 0;
        int num = 1;

        while (true) {

            if (checkUglyNumber(num)) {
                count++;
                if (count == n)
                    return num;
            }

            num++;
        }


    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.nthUglyNumber(10)
         << " | Expected: 12" << endl;

    // Example 2
    cout << "Output: " << sol.nthUglyNumber(1)
         << " | Expected: 1" << endl;

    // Additional Test
    cout << "Output: " << sol.nthUglyNumber(15)
         << " | Expected: 24" << endl;

    return 0;
}

// Time Complexity : U(n) + log2(num) where U(n) : nth Ugly number .
// Space Complexity : O(1) 


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  
    int nthUglyNumber(int n){

        vector<int>dp(n + 1 , 0 ) ;
        dp[1] = 1 ; 

        int i2 = 1 , i3  = 1 , i5 = 1 ;

        for(int i = 2 ; i <= n ; i ++ ){

            int nextUglyNum = min({dp[i2] * 2 , dp[i3]* 3 , dp[i5] * 5}) ; 
            dp[i] = nextUglyNum ; 

            if(nextUglyNum == dp[i2] * 2) i2 ++ ; 
            if(nextUglyNum == dp[i3] * 3) i3 ++ ; 
            if(nextUglyNum == dp[i5] * 5) i5 ++ ; 

        }

        return dp[n] ;

    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.nthUglyNumber(10)
         << " | Expected: 12" << endl;

    // Example 2
    cout << "Output: " << sol.nthUglyNumber(1)
         << " | Expected: 1" << endl;

    // Additional Test
    cout << "Output: " << sol.nthUglyNumber(15)
         << " | Expected: 24" << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n) 



