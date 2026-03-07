#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems){

    }
};

void printVec(vector<int>& v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    int n1 = 8, m1 = 2;
    vector<int> group1 = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> before1 = {
        {},{6},{5},{6},{3,6},{},{},{}
    };

    vector<int> res1 = sol.sortItems(n1, m1, group1, before1);
    cout << "Output: ";
    printVec(res1);
    cout << " | Expected: [6,3,4,1,5,2,0,7]" << endl;

    // Example 2
    int n2 = 8, m2 = 2;
    vector<int> group2 = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> before2 = {
        {},{6},{5},{6},{3},{},{4},{}
    };

    vector<int> res2 = sol.sortItems(n2, m2, group2, before2);
    cout << "Output: ";
    printVec(res2);
    cout << " | Expected: []" << endl;

    return 0;
}