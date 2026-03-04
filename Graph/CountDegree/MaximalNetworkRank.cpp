#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads){

        unordered_map<int , unordered_set<int>>mpp ; 

        for(vector<int>road : roads){

            int a = road[0] ; 
            int b = road[1] ; 

            mpp[a].insert(b) ; 
            mpp[b].insert(a) ; 
        }

        int maxRank = INT_MIN ;

        for(int i = 0 ; i < n ; i ++ ){

            int rank = 0 ; 

            for(int j = i + 1 ; j < n ; j ++ ){

                int degA = mpp[i].size() ; 
                int degB = mpp[j].size() ; 

                rank = degA + degB ; 

                if(mpp[i].find(j) != mpp[i].end()){
                    rank = rank - 1 ; 
                }

                maxRank = max(maxRank , rank) ; 
            
           }
        }

        return maxRank ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 4;
    vector<vector<int>> roads1 = {{0,1},{0,3},{1,2},{1,3}};
    cout << "Output: " << sol.maximalNetworkRank(n1, roads1)
         << " | Expected: 4" << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> roads2 = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << "Output: " << sol.maximalNetworkRank(n2, roads2)
         << " | Expected: 5" << endl;

    // Example 3
    int n3 = 8;
    vector<vector<int>> roads3 = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    cout << "Output: " << sol.maximalNetworkRank(n3, roads3)
         << " | Expected: 5" << endl;

    return 0;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n)

