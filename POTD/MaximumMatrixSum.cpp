#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        long long result = 0;
        bool checkZero = false;
        int minElement = INT_MAX;
        int cntNegative = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    checkZero = true;

                result += abs(matrix[i][j]);
                minElement = min(abs(matrix[i][j]), minElement);
                if (matrix[i][j] < 0)
                    cntNegative++;
            }
        }

        if (checkZero || cntNegative % 2 == 0)
            return result;

        return result - 2*minElement;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, -1},
        {-1, 1}};
    cout << "Output 1: " << sol.maxMatrixSum(matrix1) << endl;
    // Expected: 4

    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {-1, -2, -3},
        {1, 2, 3}};
    cout << "Output 2: " << sol.maxMatrixSum(matrix2) << endl;
    // Expected: 16

    vector<vector<int>> matrix3 = {
        {-1}};
    cout << "Output 3: " << sol.maxMatrixSum(matrix3) << endl;
    // Expected: 1

    return 0;
}


// Time Complexity : O(n*n)
// Space Complexity : O(1)