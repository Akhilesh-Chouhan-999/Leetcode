#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    int solve(vector<int>&cuts , int startStick , int endStick , int startCut , int endCut){

        if(endCut > startCut)
        return 0 ; 

        int cost = 1e9 ; 

        for(int cut = startCut ; cut <= endCut ; cut ++){

            int leftCut  = solve(cuts , startStick , cuts[cut] , startCut , cut - 1) ;
            int rightCut = solve(cuts , cuts[cut]  , endStick  , cut + 1  , endCut ) ;
            int currCut = (endStick - startStick) + leftCut + rightCut ; 

            cost = min(cost , currCut) ; 

        }

        return cost ; 

    }


    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin() , cuts.end()) ;

        return solve(cuts , 0 , n , 0 , cuts.size() - 1) ; 

    }
};

int main() {
    Solution sol;
    
    // Test case 1: n = 9, cuts = [5,4,6]
    vector<int> cuts1 = {5, 4, 6};
    cout << "Test 1: n = 9, cuts = [5,4,6]" << endl;
    cout << "Output: " << sol.minCost(9, cuts1) << endl;
    cout << "Expected: 22" << endl << endl;
    
    // Test case 2: n = 7, cuts = [1,3,4,5]
    vector<int> cuts2 = {1, 3, 4, 5};
    cout << "Test 2: n = 7, cuts = [1,3,4,5]" << endl;
    cout << "Output: " << sol.minCost(7, cuts2) << endl;
    cout << "Expected: 16" << endl << endl;
    
    // Test case 3: n = 10, cuts = [2,4,6,8]
    vector<int> cuts3 = {2, 4, 6, 8};
    cout << "Test 3: n = 10, cuts = [2,4,6,8]" << endl;
    cout << "Output: " << sol.minCost(10, cuts3) << endl;
    cout << "Expected: 36" << endl << endl;
    
    return 0;
}