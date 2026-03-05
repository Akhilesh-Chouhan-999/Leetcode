#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> price1 = {2,5};
    vector<vector<int>> special1 = {{3,0,5},{1,2,10}};
    vector<int> needs1 = {3,2};
    cout << "Output: " << sol.shoppingOffers(price1, special1, needs1)
         << " | Expected: 14" << endl;

    // Example 2
    vector<int> price2 = {2,3,4};
    vector<vector<int>> special2 = {{1,1,0,4},{2,2,1,9}};
    vector<int> needs2 = {1,2,1};
    cout << "Output: " << sol.shoppingOffers(price2, special2, needs2)
         << " | Expected: 11" << endl;

    return 0;
}