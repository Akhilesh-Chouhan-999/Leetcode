#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {

        unordered_map<int , unordered_set<int> >adj ;
        vector<int>degree(n+1 , 0) ; 
        
        for(vector<int>edge : edges){
            
            int u = edge[0] ; 
            int v = edge[1] ; 
            
            adj[u].insert(v) ; 
            adj[v].insert(u) ; 
            degree[u] ++ ; 
            degree[v] ++ ; 
            
        }
        
        
        vector<int>Odd ; 

        for(int i = 1 ; i <= n ; i ++ ){
            if(degree[i] % 2 == 1){
                Odd.push_back(i) ; 
            }
        }

        if(Odd.size() == 0) return true ; 

        if(Odd.size() == 2){

            int a = Odd[0] ; 
            int b = Odd[1] ; 

            if(adj[a].find(b) == adj[a].end()) 
            return true ; 

            for(int i = 1 ; i <= n ; i ++ ){
                if( i != a && i != b){

                    if(adj[i].find(a) == adj[i].end() && adj[i].find(b) == adj[i].end())
                    return true ; 
                }

            }
            
            return false ; 

        }

        if(Odd.size() == 4){
            int a = Odd[0];
            int b = Odd[1];
            int c = Odd[2];
            int d = Odd[3];

            if (adj[a].find(b) == adj[a].end() &&
                adj[c].find(d) == adj[c].end())
                return true;

            if (adj[a].find(c) == adj[a].end() &&
                adj[b].find(d) == adj[b].end())
                return true;

            if (adj[a].find(d) == adj[a].end() &&
                adj[b].find(c) == adj[b].end())
                return true;

            return false;
        }

        return false ; 

    }
};

int main() {

    Solution sol;

    // Test Case 1
    int n1 = 5;
    vector<vector<int>> edges1 = {
        {1,2},{2,3},{3,4},{4,2},{1,4},{2,5}
    };
    cout << "Test Case 1: " 
         << (sol.isPossible(n1, edges1) ? "true" : "false") 
         << endl;

    // Test Case 2
    int n2 = 4;
    vector<vector<int>> edges2 = {
        {1,2},{3,4}
    };
    cout << "Test Case 2: " 
         << (sol.isPossible(n2, edges2) ? "true" : "false") 
         << endl;

    // Test Case 3
    int n3 = 4;
    vector<vector<int>> edges3 = {
        {1,2},{1,3},{1,4}
    };
    cout << "Test Case 3: " 
         << (sol.isPossible(n3, edges3) ? "true" : "false") 
         << endl;

    return 0;
}


// Time Complexity : O(E + V ) 
// Space Complelxity : O(E + V ) where E is the edges and V is the vertices . 

