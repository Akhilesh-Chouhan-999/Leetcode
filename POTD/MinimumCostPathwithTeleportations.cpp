#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k){

        int m = grid.size() ; 
        int n = grid[0].size() ; 

        
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {1, 3, 3},
        {2, 5, 4},
        {4, 3, 5}
    };
    int k1 = 2;
    cout << "Output 1: " << obj.minCost(grid1, k1) << endl;

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    int k2 = 1;
    cout << "Output 2: " << obj.minCost(grid2, k2) << endl;

    return 0;
}
