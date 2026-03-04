#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    int minimumTotal(vector<vector<int>>& triangle){

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> triangle1 = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << "Output: " << sol.minimumTotal(triangle1)
         << " | Expected: 11" << endl;

    // Example 2
    vector<vector<int>> triangle2 = {
        {-10}
    };
    cout << "Output: " << sol.minimumTotal(triangle2)
         << " | Expected: -10" << endl;

    return 0;
}