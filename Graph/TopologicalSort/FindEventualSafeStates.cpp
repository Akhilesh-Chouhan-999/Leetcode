/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){

        int V = graph.size() ;
        
        unordered_map<int , vector<int>>adj ; 

        vector<int>outDegree(V  , 0) ; 

        for(int u = 0 ; u < V ; u ++ ){

            for(int &v : graph[u]){

                adj[v].push_back(u) ; 

                outDegree[u] ++ ; 

            }

        }

        queue<int>que ; 

        for(int i = 0 ; i < V ; i ++ ){
            
            if(outDegree[i] == 0)
            que.push(i) ; 
        }

        vector<int>result ; 

        while(!que.empty()){

            int node = que.front() ; 
            que.pop() ; 

            result.push_back(node) ; 

            for(int &v : adj[node]){

                if(--outDegree[v] == 0)
                que.push(v) ; 

            }

        }


        sort(begin(result) , end(result)) ;

        return result ; 
        
    }
};

void printVector(const vector<int>& v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> graph1 = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> res1 = sol.eventualSafeNodes(graph1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [2, 4, 5, 6]" << endl;

    // Example 2
    vector<vector<int>> graph2 = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> res2 = sol.eventualSafeNodes(graph2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [4]" << endl;

    return 0;
}

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCycle(unordered_map<int , vector<int>>& adj, int u,vector<bool>& visited,vector<bool>& recVisited,vector<bool>& checkSafe){

        visited[u] = true ; 
        recVisited[u] = true ; 

        for(int &v : adj[u]){

            if(!visited[v] && isCycle(adj , v , visited , recVisited , checkSafe)){
                checkSafe[u] = false ; 
                return true ; 
            }
            else if(recVisited[v]){
                checkSafe[u] = false ; 
                return true ; 
            }
        }

        recVisited[u] = false ; 
        checkSafe[u] = true ; 

        return false ; 

    }



    vector<int> eventualSafeNodes(vector<vector<int>>& graph){

        int V = graph.size() ;

          
        unordered_map<int , vector<int>>adj ; 

        for(int u = 0 ; u < V ; u ++ ){

            for(int &v : graph[u]){
                adj[u].push_back(v) ;
            }
        }


        vector<bool> visited(V,false);
        vector<bool> recVisited(V,false);
        vector<bool> checkSafe(V,false);


        for(int i = 0 ; i < V ; i ++ ){

            if(!visited[i] && isCycle(adj , i , visited , recVisited , checkSafe)){
                isCycle(adj , i , visited , recVisited , checkSafe) ; 
             }
        }

        vector<int>result ; 

        for(int i = 0 ; i < V ; i ++ ){
            if(checkSafe[i]){
                result.push_back(i) ; 
            }
        }
        
        sort(begin(result) , end(result)) ; 

        return result ; 
        
    }
};

void printVector(const vector<int>& v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> graph1 = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> res1 = sol.eventualSafeNodes(graph1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [2, 4, 5, 6]" << endl;

    // Example 2
    vector<vector<int>> graph2 = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> res2 = sol.eventualSafeNodes(graph2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [4]" << endl;

    return 0;
}

// Time Complexity : O(V + E)
// Space Complexity : O(V + E)
