#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCycle(unordered_map<int , vector<int>>&adj , int u , vector<bool>&visited , vector<bool>&recVisited){

        visited[u] = true ; 
        recVisited[u] = true ; 


        for(int &v : adj[u]){

            if(!visited[v] && isCycle(adj , v , visited , recVisited)){
                return true ; 
            }
            else if(recVisited[v]){
                return true ; 
            }
        }

        recVisited[u] = false ; 

        return false ; 

    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){

        int V = prerequisites.size() ; 

        unordered_map<int , vector<int>>adj ; 

        for(vector<int>prerequisite : prerequisites){
            int a = prerequisite[0] ;
            int b = prerequisite[1] ; 

            adj[b].push_back(a) ; 
        }


        vector<bool>visited(V+1 , false) ; 
        vector<bool>recVisited(V+1 , false) ; 

        for( int i = 0 ; i < V ; i ++ ){

            if(!visited[i] && isCycle(adj , i , visited , recVisited)){
                return false ; 
            }

        }


        return true ; 
        
    }
};

int main() {
    Solution sol;

    // Example 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1,0}};
    cout << "Output: " << sol.canFinish(numCourses1, prerequisites1)
         << " | Expected: true" << endl;

    // Example 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1,0},{0,1}};
    cout << "Output: " << sol.canFinish(numCourses2, prerequisites2)
         << " | Expected: false" << endl;

    return 0;
}