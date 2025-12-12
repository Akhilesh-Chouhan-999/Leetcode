#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
       
        return {};
    }
};

int main() {
    // Hardcoded test case 1
    int numberOfUsers = 6;

    vector<vector<string>> events = {
        {"MESSAGE", "1", "id1,id2,id3"},
        {"MESSAGE", "2", "ALL"},
        {"MESSAGE", "3", "GROUP:1,2"},
        {"MESSAGE", "10", "id5"},
        {"MESSAGE", "12", "id2,id4,id6"}
    };

    Solution sol;
    vector<int> ans = sol.countMentions(numberOfUsers, events);

    // Print the output
    cout << "Output: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
