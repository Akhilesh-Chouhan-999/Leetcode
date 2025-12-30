#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        
    }
};

void printGrid(const vector<vector<int>> &grid)
{
    for (auto &row : grid)
    {
        for (int x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution sol;

    vector<vector<int>> grid1 = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}};

    cout << "Test Case 1:\nGrid:\n";
    printGrid(grid1);
    cout << "Output: " << sol.numMagicSquaresInside(grid1) << endl;
    cout << "Expected: 1\n\n";

    // ---------- Test Case 2 ----------
    vector<vector<int>> grid2 = {
        {8}};

    cout << "Test Case 2:\nGrid:\n";
    printGrid(grid2);
    cout << "Output: " << sol.numMagicSquaresInside(grid2) << endl;
    cout << "Expected: 0\n\n";

    // ---------- Additional Edge Test ----------
    vector<vector<int>> grid3 = {
        {1, 2},
        {3, 4}};

    cout << "Test Case 3 (No 3x3 possible):\nGrid:\n";
    printGrid(grid3);
    cout << "Output: " << sol.numMagicSquaresInside(grid3) << endl;
    cout << "Expected: 0\n";

    return 0;
}
