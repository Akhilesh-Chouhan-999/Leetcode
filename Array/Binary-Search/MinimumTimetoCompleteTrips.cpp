#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, long long totalTrips) {
        // Your logic here
        return 0;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> time1 = {1, 2, 3};
    long long trips1 = 5;
    cout << "Test 1 Output: " << sol.minimumTime(time1, trips1) << endl;

    // Test Case 2
    vector<int> time2 = {2};
    long long trips2 = 10;
    cout << "Test 2 Output: " << sol.minimumTime(time2, trips2) << endl;

    // Test Case 3
    vector<int> time3 = {5, 10, 10};
    long long trips3 = 9;
    cout << "Test 3 Output: " << sol.minimumTime(time3, trips3) << endl;

    // Test Case 4
    vector<int> time4 = {3, 3, 3};
    long long trips4 = 7;
    cout << "Test 4 Output: " << sol.minimumTime(time4, trips4) << endl;

    // Test Case 5
    vector<int> time5 = {1, 5, 7, 10};
    long long trips5 = 20;
    cout << "Test 5 Output: " << sol.minimumTime(time5, trips5) << endl;

    return 0;
}
