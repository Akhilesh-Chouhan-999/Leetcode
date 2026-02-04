#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

 using ll = long long ; 

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k){

     int n = prices.size() ; 

     vector<ll>prefixPriceStrategy(n+1,0) ;
     vector<ll>prefixPrice(n+1,0) ; 

     for(int i = 0 ; i < n ; i ++ ){
          prefixPrice[i+1] = prefixPrice[i] + prices[i] ;
          prefixPriceStrategy[i+1] = prefixPriceStrategy[i] + strategy[i]*prices[i] ; 
     } 


     ll totalSum = prefixPriceStrategy.back() ; 
     ll result = totalSum ; 
     int i = 0 ; 

     for(int j = k - 1 ; j < n ; j ++ ){

          if( j - i + 1 >= k){

               ll windowSumOfkElement = prefixPriceStrategy[j+1] - prefixPriceStrategy[i] ; 
               ll HalfKElementSum = prefixPrice[j+1] - prefixPrice[j - k / 2+1] ;
               ll sol = totalSum - windowSumOfkElement  + HalfKElementSum ; 

               result = max(result , sol) ;
               i ++  ;
          }
     }

     return result ; 

       
    }
};


int main() {
    Solution sol;

    // -------- Test Case 1 --------
    vector<int> prices1   = {4, 2, 8};
    vector<int> strategy1 = {-1, 0, 1};
    int k1 = 2;

    cout << "Test Case 1 Output: "
         << sol.maxProfit(prices1, strategy1, k1)
         << endl;

    // -------- Test Case 2 --------
    vector<int> prices2   = {5, 4, 3};
    vector<int> strategy2 = {1, 1, 0};
    int k2 = 2;

    cout << "Test Case 2 Output: "
         << sol.maxProfit(prices2, strategy2, k2)
         << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)