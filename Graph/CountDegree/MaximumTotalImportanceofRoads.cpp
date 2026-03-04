#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int>degree(n , 0) ; 

        for(vector<int>&road : roads){
            
            int a = road[0] ; 
            int b = road[1] ;

            degree[a] ++ ; 
            degree[b] ++ ; 

        }

        sort(degree.begin() , degree.end()) ; 

       long long result = 0 ; 

       for(int i = 0 ; i < n ; i ++ ){

        result += 1LL * ( i + 1 ) * degree[i] ; 

       }

       return result ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 5;
    vector<vector<int>> roads1 = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    cout << "Output: " << sol.maximumImportance(n1, roads1)
         << " | Expected: 43" << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> roads2 = {{0,3},{2,4},{1,3}};
    cout << "Output: " << sol.maximumImportance(n2, roads2)
         << " | Expected: 20" << endl;

    return 0;
}

// Time Complexity : O(n*log(n))
// Space Complexty : O(n)