#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        if(complexity.empty()) return 0  ; 

        const int MOD = 1e9 + 7 ; 
        int n =  complexity.size() ;
        int root = complexity[0] ; 

        int result = 1 ; 

        for(int i = 1 ; i < n ; i ++){

            if(root >= complexity[i]){
                return 0 ; 
            }
            else{
                result =  (1LL* result * ( n - i) ) % MOD ; 
            }

        }

        return result ; 
        
    }
};


int main(){

    Solution sol ; 

     vector<vector<int>> testCases = { 
        {},                         // Edge case: empty input
        {1},                        // Single element
        {1, 2, 3},                  // Strictly increasing → example
        {3, 2, 1},                  // Strictly decreasing → likely 0
        {3,3,3,4,4,4},              // Example: output 0
        {1, 3, 2},                  // Random small
        {2, 1, 3, 4},               // Complexity lowers then rises
        {1, 5, 3, 6, 4},            // Mixed ups/downs
        {1, 10, 2, 20, 5, 30},      // Multiple increasing segments
        {5, 1, 2, 3, 4},            // First is large, may restrict unlocking
        {1, 1000000000},            // Large values but valid
        {10, 20, 30, 40, 50},       // Fully increasing large
        {5, 4, 4, 4, 6},            // Equal blocks, limited parents
        {1, 2, 2, 3, 3, 3, 4},      // Many equal groups
        {7, 7, 7, 7},               // All equal → impossible except index 0
    };


    for(vector<int>testCase : testCases){
        cout << sol.countPermutations(testCase) << endl; 
    }

    return 0 ; 
}