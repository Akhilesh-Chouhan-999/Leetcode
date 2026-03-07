#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){

        unordered_map<int , vector<int>>adj ; 
        vector<int>inDegree(n , 0) ; 

        for(vector<int>&edge : edges){

            int from = edge[0] ; 
            int to = edge[1] ; 

            adj[from].push_back(to) ;
            inDegree[to] ++ ; 
        }

        queue<int>que ; 
        vector<vector<int>>result(n) ; 

        for(int i = 0 ; i < n ; i ++ ){

            if(inDegree[i] == 0){
                que.push(i) ; 
            }
        }


        while (!que.empty()){

            int size = que.size() ; 
            
            while(size --){

                int node = que.front() ; 
                que.pop() ; 

                for(int &v : adj[node]){

                    if(!result[node].empty()){
                        for(int element : result[node]){
                            result[v].push_back(element) ; 
                        }
                    }

                    result[v].push_back(node) ; 

                    if( -- inDegree[v]  == 0){
                        sort(result[v].begin(), result[v].end());
                        result[v].erase(unique(result[v].begin(), result[v].end()), result[v].end());
                        que.push(v) ;
                    }

                }

            }
        }
        
        return result ; 
        

    }
};

void print2D(const vector<vector<int>>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << "[";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j + 1 < v[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]";


    

}

int main() {
    Solution sol;

    // Example 1
    int n1 = 8;
    vector<vector<int>> edges1 = {
        {0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}
    };

    vector<vector<int>> res1 = sol.getAncestors(n1, edges1);
    cout << "Output: ";
    print2D(res1);
    cout << endl;
    cout << "Expected: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]" << endl;

    cout << endl << endl; 

    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {
        {0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}
    };

    vector<vector<int>> res2 = sol.getAncestors(n2, edges2);
    cout << "Output: ";
    print2D(res2);
    cout << endl;
    cout << "Expected: [[],[0],[0,1],[0,1,2],[0,1,2,3]]" << endl;

    return 0;
}


// Time Complexity : O(VE + V² log V)
// Space Complexity :  O( V²)