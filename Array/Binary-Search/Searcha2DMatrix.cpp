/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        for(int i = 0 ; i < m ; i ++ )
        {
            for(int j = 0 ; j < n ; j ++) 
            {
                if(matrix[i][j] == target)
                {
                    return true ; 
                }
            }
        }

        return false ; 
    }
};

void runTest(vector<vector<int>> matrix, int target, Solution& sol) {
    bool ans = sol.searchMatrix(matrix, target);

    cout << "Matrix:" << endl;
    for (auto& row : matrix) {
        cout << "[ ";
        for (int x : row) cout << x << " ";
        cout << "]" << endl;
    }

    cout << "Target = " << target
         << "  ->  " << (ans ? "Found" : "Not Found") << endl;

    cout << "---------------------------------" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    runTest({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3, sol);

    // Test Case 2
    runTest({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13, sol);

    // Test Case 3
    runTest({{1}}, 1, sol);

    // Test Case 4
    runTest({{1,2,3},{4,5,6},{7,8,9}}, 9, sol);

    // Test Case 5
    runTest({{5,10},{15,20}}, 15, sol);

    return 0;
}


// Time complexity : O(m*n)

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 


        int left  = 0 ; 
        int right = m * n - 1 ; 


        while(left <= right)
        {
            int mid = left + (right - left) / 2 ; 

            int row = mid / m ; 
            int col = mid % n ; 

            if(matrix[row][col] == target)
            {
                return true ; 
            }


            else if(matrix[row][col] < target)
            {
                left = mid + 1 ; 
            }

            else
            right = mid - 1 ; 
        }
        

        return false ; 

    }
};

void runTest(vector<vector<int>> matrix, int target, Solution& sol) {
    bool ans = sol.searchMatrix(matrix, target);

    cout << "Matrix:" << endl;
    for (auto& row : matrix) {
        cout << "[ ";
        for (int x : row) cout << x << " ";
        cout << "]" << endl;
    }

    cout << "Target = " << target
         << "  ->  " << (ans ? "Found" : "Not Found") << endl;

    cout << "---------------------------------" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    runTest({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3, sol);

    // Test Case 2
    runTest({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13, sol);

    // Test Case 3
    runTest({{1}}, 1, sol);

    // Test Case 4
    runTest({{1,2,3},{4,5,6},{7,8,9}}, 9, sol);

    // Test Case 5
    runTest({{5,10},{15,20}}, 15, sol);

    return 0;
}


