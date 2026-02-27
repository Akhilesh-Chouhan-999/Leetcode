/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(unordered_map<int , vector<int>>& adj  , vector<bool>&visited , int u , int &dest ) {

        if( u == dest){
            return true ; 
        }

        visited[u] = true ; 

        for(auto v : adj[u]){

            if(!visited[v] ){

                if(dfs(adj , visited , v , dest))
               return true ; 
               
            }
        }

        return false ; 


    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){

        unordered_map<int , vector<int>>adj ; 

        for(vector<int>edge : edges){
            int u = edge[0] ; 
            int v = edge[1] ; 

            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }

        vector<bool>visited(n , false)  ; 

        return dfs(adj , visited , source , destination ) ; 

    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,0}};
    int source1 = 0, destination1 = 2;

    cout << "Output: " << sol.validPath(n1, edges1, source1, destination1)
         << " | Expected: 1" << endl;  // true -> 1

    // ---------- Example 2 ----------
    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    int source2 = 0, destination2 = 5;

    cout << "Output: " << sol.validPath(n2, edges2, source2, destination2)
         << " | Expected: 0" << endl;  // false -> 0

    return 0;
}
Time Complexity : O( E + V)
Space Complexity : O( E + V)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(unordered_map<int , vector<int>>& adj  , vector<bool>visited , int &source , int &destination ) {


        stack<int>st ; 
        st.push(source) ; 

        while(!st.empty()){

            int u = st.top() ; 
            st.pop() ;  

            if( u == destination)
            return true ; 

            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[v] = true ; 
                    st.push(v) ; 
                }
            }
        }

        return false ; 


    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){

        unordered_map<int , vector<int>>adj ; 

        for(vector<int>edge : edges){
            int u = edge[0] ; 
            int v = edge[1] ; 

            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }

        vector<bool>visited(n , false)  ; 

        return dfs(adj , visited , source , destination ) ; 

    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,0}};
    int source1 = 0, destination1 = 2;

    cout << "Output: " << sol.validPath(n1, edges1, source1, destination1)
         << " | Expected: 1" << endl;  // true -> 1

    // ---------- Example 2 ----------
    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    int source2 = 0, destination2 = 5;

    cout << "Output: " << sol.validPath(n2, edges2, source2, destination2)
         << " | Expected: 0" << endl;  // false -> 0

    return 0;
}


// Time Complexity : O( V + E ) where V is the vertices and E is the edges  . 
// Space Complexity : O( V + E ) where V is the vertices and E is the edges . 