#include <bits/stdc++.h>
using namespace std;

class Solution {
public:




    string largestNumber(vector<int>& cost, int target){

    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> cost1 = {4,3,2,5,6,7,2,5,5};
    int target1 = 9;
    cout << "Test Case 1 Output: " 
         << obj.largestNumber(cost1, target1) << endl;

    // Test Case 2
    vector<int> cost2 = {7,6,5,5,5,6,8,7,8};
    int target2 = 12;
    cout << "Test Case 2 Output: " 
         << obj.largestNumber(cost2, target2) << endl;

    // Test Case 3
    vector<int> cost3 = {2,4,6,2,4,6,4,4,4};
    int target3 = 5;
    cout << "Test Case 3 Output: " 
         << obj.largestNumber(cost3, target3) << endl;

    return 0;
}