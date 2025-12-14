#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        
        long long result = 0 ; 

    }
};

int main() {
    Solution obj;

    int hp1 = 10;
    vector<int> damage1 = {2, 3, 5};
    vector<int> requirement1 = {1, 2, 3};

    int hp2 = 15;
    vector<int> damage2 = {4, 6, 2};
    vector<int> requirement2 = {2, 3, 1};

    cout << "Test Case 1 Output: "
         << obj.totalScore(hp1, damage1, requirement1) << endl;

    cout << "Test Case 2 Output: "
         << obj.totalScore(hp2, damage2, requirement2) << endl;

    return 0;
}
