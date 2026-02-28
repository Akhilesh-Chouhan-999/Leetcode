#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n,
                           vector<vector<int>>& edges,
                           vector<int>& queries){


        vector<int>inDegree(n+1 , 0) ; 

        for(vector<int>&edge : edges){

            int u = edge[0] ;
            int v = edge[1] ; 

            if( u < v ){
                inDegree[u] ++ ; 
                inDegree[v] ++ ; 
            }
        }

        vector<int>validPairs ;

        for(int i = 0 ; i <= n ; i ++ ){
            for(int j = i + 1 ; j <= n ; j ++ ){

                int a = inDegree[i] ; 
                int b = inDegree[j] ; 

                validPairs.push_back(a+b) ; 

            }
        }

        vector<int>result ;  

        for(int query : queries){

            for(int pair : validPairs){

                if(pair >= query){
                    result.push_back(pair) ;
                }
            }
        }

                return result ; 

        }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{1,2},{2,4},{1,3},{2,3},{2,1}};
    vector<int> queries1 = {2, 3};

    vector<int> res1 = sol.countPairs(n1, edges1, queries1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [6, 5]" << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{1,5},{1,5},{3,4},{2,5},{1,3},{5,1},{2,3},{2,5}};
    vector<int> queries2 = {1, 2, 3};

    vector<int> res2 = sol.countPairs(n2, edges2, queries2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [10, 8, 4]" << endl;

    return 0;
}
