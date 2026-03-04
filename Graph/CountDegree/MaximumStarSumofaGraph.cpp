#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k){

        int maxElement =   *max_element(vals.begin() , vals.end()) ; 
        if(edges.size() == 0){
           return maxElement ; 
        }

        unordered_map<int , vector<int>>adj ;

        for(vector<int>edge : edges){
            int u = edge[0] ;
            int v = edge[1] ; 

            adj[u].push_back(vals[v]) ; 
            adj[v].push_back(vals[u]) ;  
        }


        int ans = INT_MIN ; 

        for(auto p : adj){

            int element = p.first ; 

            vector<int>connEdges = p.second ; 

            sort(connEdges.begin() , connEdges.end() , greater<int>()) ;

            int result = vals[element] ;

            for(int i = 0 ; i < k ; i ++ ){

                if( i == connEdges.size() || connEdges[i] < 0)
                break; 

                result += connEdges[i] ; 
            }

            ans = max(ans , result) ; 

            
        }

        return max(ans , maxElement) ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> vals1 = {1,2,3,4,10,-10,-20};
    vector<vector<int>> edges1 = {{0,1},{1,2},{1,3},{3,4},{3,5},{3,6}};
    int k1 = 2;
    cout << "Output: " << sol.maxStarSum(vals1, edges1, k1)
         << " | Expected: 16" << endl;

    // Example 2
    vector<int> vals2 = {-5};
    vector<vector<int>> edges2 = {};
    int k2 = 0;
    cout << "Output: " << sol.maxStarSum(vals2, edges2, k2)
         << " | Expected: -5" << endl;

    return 0;
}

// Time Complexity : 
// O(V)            --> max_element
// + O(E)          --> building adjacency
// + O(V)          --> iterating nodes
// + O(E log E)    --> sorting neighbor lists
// + O(Vk)         --> picking top neighbors

// Space Complexity :
// O(V + E)