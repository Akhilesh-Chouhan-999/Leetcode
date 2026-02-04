#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    void dfs(int u , unordered_map<int , vector<int>>&adj , vector<bool>&visited , int& cnt){

        if(visited[u])
         return ; 

        visited[u] = true ; 

        for(int v : adj[u]){
            if(!visited[v]){
                cnt ++ ; 
                dfs(v , adj , visited , cnt) ; 
            }
        }

        return ; 

    }


    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size() ; 
        unordered_map<int , vector<int>>adj ; 

        for(int i = 0 ; i < n ; i ++ ){

                int x1 = bombs[i][0] ; 
                int y1 = bombs[i][1] ; 
                int r1 = bombs[i][2] ; 

            for(int j = 0 ; j < n ; j ++ ){
                if( i == j)
                 continue; 

                int x2 = bombs[j][0] ; 
                int y2 = bombs[j][1] ; 
                int r2 = bombs[j][2] ; 

                long long dx = x2 - x1 ; 
                long long dy = y2 - y1 ; 


                long long distance = 1LL*dx*dx + 1LL*dy*dy ; 


                if(r1 >= sqrt(distance)){
                    adj[i].push_back(j) ; 
                }

 
            }
        }

        int result = INT_MIN ; 

        for(int i = 0 ; i < n ; i ++ ){

            vector<bool>visited(n,false) ; 
            int cnt = 1 ; 
            dfs(i , adj , visited , cnt ) ;
            
            result = max(result , cnt) ; 

        }
   

        return result ; 
   
    }
};
int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> bombs1 = {{2,1,3},{6,1,4}};
    cout << "Output: " << sol.maximumDetonation(bombs1)
         << " | Expected: 2" << endl;

    // Test case 2
    vector<vector<int>> bombs2 = {{1,1,5},{10,10,5}};
    cout << "Output: " << sol.maximumDetonation(bombs2)
         << " | Expected: 1" << endl;

    // Test case 3
    vector<vector<int>> bombs3 = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    cout << "Output: " << sol.maximumDetonation(bombs3)
         << " | Expected: 5" << endl;

    return 0;
}

// Time Complexity : O( (E + V) *n  ) => O( n ^ 3)
// Space Complexity : O(n ^ 2 + n + n ) = O ( n ^ 2)