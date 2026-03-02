#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid){

        int m = grid.size() ; 
        int n = grid[0].size() ; 


        
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {
        {0,0,1},
        {1,1,0},
        {1,0,0}
    };
    cout << "Output: " << sol.minSwaps(grid1)
         << " | Expected: 3" << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {0,1,1,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,1,1,0}
    };
    cout << "Output: " << sol.minSwaps(grid2)
         << " | Expected: -1" << endl;

    // Example 3
    vector<vector<int>> grid3 = {
        {1,0,0},
        {1,1,0},
        {1,1,1}
    };
    cout << "Output: " << sol.minSwaps(grid3)
         << " | Expected: 0" << endl;

    return 0;
}