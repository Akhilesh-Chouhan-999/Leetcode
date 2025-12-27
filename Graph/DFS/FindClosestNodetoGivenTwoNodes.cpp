#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

    }
};

int main() {
    Solution sol;

    // 🔹 Test Case 1
    vector<int> edges1 = {2, 2, 3, -1};
    int node1_1 = 0, node2_1 = 1;
    cout << sol.closestMeetingNode(edges1, node1_1, node2_1) << endl;
    // Expected: 2

    // 🔹 Test Case 2
    vector<int> edges2 = {1, 2, -1};
    int node1_2 = 0, node2_2 = 2;
    cout << sol.closestMeetingNode(edges2, node1_2, node2_2) << endl;
    // Expected: 2

    // 🔹 Test Case 3 (no meeting node)
    vector<int> edges3 = {1, -1, -1};
    int node1_3 = 0, node2_3 = 2;
    cout << sol.closestMeetingNode(edges3, node1_3, node2_3) << endl;
    // Expected: -1

    return 0;
}
