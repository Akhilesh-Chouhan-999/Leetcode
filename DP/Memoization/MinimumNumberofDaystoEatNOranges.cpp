/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = INT_MAX ; 
  void dfs(int n, int cntDay) {

    if(cntDay >= result) return;  
    if(n == 0){
        result = min(result, cntDay);
        return;
    }

    dfs(n - 1, cntDay + 1);

    if(n % 2 == 0)
        dfs(n / 2, cntDay + 1);

    if(n % 3 == 0)
        dfs(n / 3, cntDay + 1);

    }


    int minDays(int n){

        dfs(n , 0) ; 

        return result ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.minDays(10)
         << " | Expected: 4" << endl;

    // Example 2
    cout << "Output: " << sol.minDays(6)
         << " | Expected: 3" << endl;

    // Additional Test
    cout << "Output: " << sol.minDays(1)
         << " | Expected: 1" << endl;

    return 0;
}

// Time complexity : O(n)
// Space Complexity  : O(n) 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int , int>dp ; 

  int dfs(int n ) {

    if(n == 0) return 0 ; 
    if(n == 1) return 1 ; 

    if(dp.count(n)){
        return dp[n] ; 
    }
    int divBy2 = n % 2 + dfs(n/2) ;
    int divBy3 = n % 3 + dfs(n/3) ; 
    
    return dp[n] = 1 + min(divBy2 , divBy3) ; 

  }


    int minDays(int n){
        return dfs(n) ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.minDays(10)
         << " | Expected: 4" << endl;

    // Example 2
    cout << "Output: " << sol.minDays(6)
         << " | Expected: 3" << endl;

    // Additional Test
    cout << "Output: " << sol.minDays(1)
         << " | Expected: 1" << endl;

    return 0;
}

// Time complexity :  O(log(n))
// Space Complexity  : O(log(n))