#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges){

        int n = edges.size() ; 

        vector<long long>inDegreeSum(n , 0) ; 

        for(int i = 0 ; i < n ; i ++){

            int u = i ; 
            int v = edges[i] ; 

            inDegreeSum[v] += u ; 
        }


        long long sum = LLONG_MIN; ; 
        int result = -1 ; 

        for(int i = 0 ; i < n ; i ++ ){
            
            if(inDegreeSum[i] > sum){
                sum = inDegreeSum[i] ; 
                result = i ; 
            }
        }

        return result ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> edges1 = {1,0,0,0,0,7,7,5};
    cout << "Output: " << sol.edgeScore(edges1)
         << " | Expected: 7" << endl;

    // Example 2
    vector<int> edges2 = {2,0,0,2};
    cout << "Output: " << sol.edgeScore(edges2)
         << " | Expected: 0" << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Compelxity : O(n)