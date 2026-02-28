#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges){

        vector<int>inDegree(n , 0) ; 

        for(vector<int>&edge : edges){
            int u = edge[0] ; 
            int v = edge[1] ; 


            inDegree[v] ++ ; 
        }

        int result = -1 ; 

        for(int i = 0 ; i < n ; i ++ ){
            if(inDegree[i] == 0){
                if(result != -1)
                return -1 ; 

                result = i ; 
            }
        }

        return result ; 

    }
};



int main() {
    Solution sol;

    // Example 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1}, {1,2}};
    cout << "Output: " << sol.findChampion(n1, edges1)
         << " | Expected: 0" << endl;

    // Example 2
    int n2 = 4;
    vector<vector<int>> edges2 = {{0,2}, {1,3}, {1,2}};
    cout << "Output: " << sol.findChampion(n2, edges2)
         << " | Expected: -1" << endl;

    return 0;
}