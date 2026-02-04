#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long result = 0 ; 

        int minNeed = min(need1 , need2) ; 

        if(costBoth < cost1 + cost2){
            result +=  1LL*minNeed * costBoth ;
            need1 -= minNeed ; 
            need2 -= minNeed ;  
        }

        
         result += min( 1LL* need1 * costBoth , 1LL*need1 * cost1) ; 
         result += min( 1LL*need2 * costBoth , 1LL*need2 * cost2) ;

        return result ; 

       
       
    }
};

int main() {
    Solution sol;

    // Test case 1
    // cost1 = 3, cost2 = 5, costBoth = 6
    // need1 = 4, need2 = 2
    // Optimal: buy 2 "both" + 2 "only1"
    // Cost = 2*6 + 2*3 = 18
    cout << sol.minimumCost(3, 5, 6, 4, 2) << "  (Expected: 18)" << endl;

    // Test case 2
    // cost1 = 10, cost2 = 7, costBoth = 12
    // need1 = 1, need2 = 3
    // Optimal: buy 1 "both" + 2 "only2"
    // Cost = 1*12 + 2*7 = 26
    cout << sol.minimumCost(10, 7, 12, 1, 3) << "  (Expected: 26)" << endl;

    // Test case 3
    // cost1 = 2, cost2 = 2, costBoth = 10
    // need1 = 5, need2 = 5
    // Optimal: no "both", buy separately
    // Cost = 5*2 + 5*2 = 20
    cout << sol.minimumCost(2, 2, 10, 5, 5) << "  (Expected: 20)" << endl;

    // Test case 4
    // cost1 = 4, cost2 = 6, costBoth = 5
    // need1 = 3, need2 = 3
    // Optimal: buy all "both"
    // Cost = 3*5 = 15
    cout << sol.minimumCost(4, 6, 5, 3, 3) << "  (Expected: 15)" << endl;

    return 0;
}


// Time Complexity : O(1)
// Space Complexity : O(1)