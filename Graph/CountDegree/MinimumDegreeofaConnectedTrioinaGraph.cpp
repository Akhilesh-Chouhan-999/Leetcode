#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges){

        unordered_map<int , unordered_set<int>>adj ;

        for(vector<int>edge : edges){

            int a = edge[0] ;
            int b = edge[1] ; 

            adj[a].insert(b) ; 
            adj[b].insert(a) ; 
        }

        int result = INT_MAX ; 


        for(int i = 1 ; i <= n ; i ++ ){

            for(int j = i + 1 ; j <= n ; j ++ ){

                for(int k = j + 1 ; k <= n ; k ++ ){

                    if(adj[i].count(j) && adj[i].count(k) && adj[j].count(k)){

                    int count = adj[i].size() + adj[j].size() +  adj[k].size() - 6 ; 
                    result = min(result , count);
                    }

                }
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 6;
    vector<vector<int>> edges1 = {{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    cout << "Output: " << sol.minTrioDegree(n1, edges1)
         << " | Expected: 3" << endl;

    // Example 2
    int n2 = 7;
    vector<vector<int>> edges2 = {{1,3},{4,1},{4,3},{2,5},{5,6},{6,7},{7,5},{2,6}};
    cout << "Output: " << sol.minTrioDegree(n2, edges2)
         << " | Expected: 0" << endl;

    return 0;
}

// Time complexity : O(n^3)
// Space Complexity : O(n+m)