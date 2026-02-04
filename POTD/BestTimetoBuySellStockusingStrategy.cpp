#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // your implementation
        return 0;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> pricesList = {
        {10, 9, 8, 7, 6},                    // Case 1
        {100, 90, 80, 70},                  // Case 2
        {3, 1, 4, 8, 2, 9},                 // Case 3 (k = n)
        {5, 5, 5, 5},                       // Case 4
        {1, 100, 1, 100, 1, 100},           // Case 5
        {1000, 1, 1000, 1, 1000},           // Case 6
        {1, 100000, 1, 100000, 1, 100000},  // Case 7
        {7, 1, 5, 3, 6, 4},                 // Case 8
        {2, 2, 2, 100, 2, 2}                // Case 9
    };

    vector<vector<int>> strategyList = {
        {-1, -1, -1, -1, -1},
        {1, 1, 1, 1},
        {-1, -1, -1, -1, -1, -1},
        {0, 0, 0, 0},
        {-1, 0, -1, 0, -1, 0},
        {1, -1, 1, -1, 1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 0, -1, 0, -1, 0},
        {-1, -1, -1, -1, -1, -1}
    };

    vector<int> kList = {
        4,  // Case 1
        2,  // Case 2
        6,  // Case 3
        2,  // Case 4
        2,  // Case 5
        4,  // Case 6
        4,  // Case 7
        2,  // Case 8
        4   // Case 9
    };

    for (int i = 0; i < pricesList.size(); i++) {
        cout << "Test Case " << i + 1 << " -> ";
        cout << obj.maxProfit(pricesList[i], strategyList[i], kList[i]) << endl;
    }

    return 0;
}
