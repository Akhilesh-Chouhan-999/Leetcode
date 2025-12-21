#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k){
        
        int n = prices.size() ; 

        long long result = 0 ;

        vector<int>prefix(n , 0) ;

        prefix[0] = prices[0]*strategy[0] ; 

        for(int i = 1 ; i < n ; i ++){
            prefix[i] = prefix[i-1] + prices[i] * strategy[i] ; 
        }

        int i = 0 ; 
        int j = 0 ; 


        while( j < n ){

            if(j - i + 1 == k){
                long long sum =  
            }


            j ++ ; 
        }



    }
};

int main() {


    int n;
    cin >> n;

    vector<int> prices(n), strategy(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> strategy[i];

    int k;
    cin >> k;

    Solution sol;
    cout << sol.maxProfit(prices, strategy, k);

    return 0;
}
