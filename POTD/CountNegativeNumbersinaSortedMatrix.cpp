/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        int result = 0 ;

        for(int i = 0 ; i < m ; i ++ ){

            int low = 0 ;
            int high = n - 1 ;
            int mid ;
            int index = -1 ;

            while(low <= high ){
                mid = low + ( high - low ) / 2 ;

                if(grid[i][mid] < 0 ){
                    index = mid ;
                    high = mid - 1 ;
                }
                else{
                    low = mid + 1 ;
                }
            }

            if(index != -1){
                result += ( n - index) ;
            }
        }

        return result ;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };
    cout << "Output: " << sol.countNegatives(grid1) << endl; // Expected: 8

    // Test Case 2
    vector<vector<int>> grid2 = {
        {3, 2},
        {1, 0}
    };
    cout << "Output: " << sol.countNegatives(grid2) << endl; // Expected: 0

    return 0;
}

// Time Complexity : O(m*log(n))

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

       
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}};
    cout << "Output: " << sol.countNegatives(grid1) << endl; // Expected: 8

    // Test Case 2
    vector<vector<int>> grid2 = {
        {3, 2},
        {1, 0}};
    cout << "Output: " << sol.countNegatives(grid2) << endl; // Expected: 0

    return 0;
}
