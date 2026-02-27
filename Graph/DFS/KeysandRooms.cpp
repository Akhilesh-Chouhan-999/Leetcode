#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(unordered_map<int , vector<int>>&adj , vector<bool>&visited ,  int u ){

        if(!visited[u]) 
        return ; 

        visited[u] = true ; 

        for(int v : adj[u]){

            if(!visited[v]){
                dfs(adj , visited , v ) ; 
            }
        }

        return  ; 

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms){

        int n = rooms.size() ; 
        unordered_map<int , vector<int >> adj ; 

        for(int u = 0 ; u < n ; u ++ ){
            for(auto v : rooms[u] ){
                adj[u].push_back(v) ; 
            }
        }

        vector<bool>visited(n , false) ;

        dfs(adj , visited , 0 ) ; 

        for(bool visit : visited){
            if(!visit) 
            return false ; 
        }

        return true ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << "Output: " << sol.canVisitAllRooms(rooms1)
         << " | Expected: 1" << endl;  // true -> 1

    // Example 2
    vector<vector<int>> rooms2 = {{1,3}, {3,0,1}, {2}, {0}};
    cout << "Output: " << sol.canVisitAllRooms(rooms2)
         << " | Expected: 0" << endl;  // false -> 0

    return 0;
}

// Time Complexity : O(V + E)
// Space Complexity : O(V + E) + O(V) 

