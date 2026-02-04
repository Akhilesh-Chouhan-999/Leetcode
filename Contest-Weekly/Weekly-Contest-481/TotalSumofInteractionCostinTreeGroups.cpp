


/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int current , int target , unordered_map<int , vector<int>>&adj , vector<bool>&visited){

        if(current == target) 
        return 0  ; 

        visited[current] = true ; 

        for(int neighbour : adj[current]){

            if(!visited[neighbour]){
                int dist = dfs(neighbour , target , adj , visited);
                
                if(dist != -1)
                return dist + 1 ; 
            }

        }

        return -1 ; 
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {

        // Step 1 : Adjacency List . 
        unordered_map<int , vector<int>>adj ; 

        for(vector<int>&edge : edges){
            int u = edge[0] ; 
            int v = edge[1] ;

            adj[u].push_back(v) ; 
            adj[v].push_back(u) ;
        }

        // Step 2 : Calculate the same group nodes . 
        long long result = 0 ; 

        for(int i = 0 ; i < n ; i ++ ){
            for(int j = i + 1; j < n ; j ++){
                vector<bool>visited(n , false) ;
                if(group[i] == group[j]){
                   result +=  dfs(i , j , adj , visited) ; 
                }
            }
        }

        return result ; 


    }
};

int main() {
    Solution sol;

    // Example 1
    {
        int n = 3;
        vector<vector<int>> edges = {{0,1},{1,2}};
        vector<int> group = {1,1,1};
        cout << "Example 1 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    // Example 2
    {
        int n = 3;
        vector<vector<int>> edges = {{0,1},{1,2}};
        vector<int> group = {3,2,3};
        cout << "Example 2 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    // Example 3
    {
        int n = 4;
        vector<vector<int>> edges = {{0,1},{0,2},{0,3}};
        vector<int> group = {1,1,4,4};
        cout << "Example 3 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    // Example 4
    {
        int n = 2;
        vector<vector<int>> edges = {{0,1}};
        vector<int> group = {9,8};
        cout << "Example 4 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    return 0;
}

Time Complexity : O(n*n*(n+e)) where n is no. of nodes and e is the edges . 
Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int current , int target , unordered_map<int , vector<int>>&adj , vector<bool>&visited){

        if(current == target) 
        return 0  ; 

        visited[current] = true ; 

        for(int neighbour : adj[current]){

            if(!visited[neighbour]){
                int dist = dfs(neighbour , target , adj , visited);
                
                if(dist != -1)
                return dist + 1 ; 
            }

        }

        return -1 ; 
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {

        // Step 1 : Adjacency List . 
        unordered_map<int , vector<int>>adj ; 

        for(vector<int>&edge : edges){
            int u = edge[0] ; 
            int v = edge[1] ;

            adj[u].push_back(v) ; 
            adj[v].push_back(u) ;
        }

        // Step 2 : Calculate the same group nodes . 
        long long result = 0 ; 

        for(int i = 0 ; i < n ; i ++ ){
            for(int j = i + 1; j < n ; j ++){
                vector<bool>visited(n , false) ;
                if(group[i] == group[j]){
                   result +=  dfs(i , j , adj , visited) ; 
                }
            }
        }

        return result ; 


    }
};

int main() {
    Solution sol;

    // Example 1
    {
        int n = 3;
        vector<vector<int>> edges = {{0,1},{1,2}};
        vector<int> group = {1,1,1};
        cout << "Example 1 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    // Example 2
    {
        int n = 3;
        vector<vector<int>> edges = {{0,1},{1,2}};
        vector<int> group = {3,2,3};
        cout << "Example 2 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    // Example 3
    {
        int n = 4;
        vector<vector<int>> edges = {{0,1},{0,2},{0,3}};
        vector<int> group = {1,1,4,4};
        cout << "Example 3 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    // Example 4
    {
        int n = 2;
        vector<vector<int>> edges = {{0,1}};
        vector<int> group = {9,8};
        cout << "Example 4 Output: "
             << sol.interactionCosts(n, edges, group) << "\n";
    }

    return 0;
}