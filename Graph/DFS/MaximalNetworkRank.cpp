#include<bits/stdc++.h>
using namespace std ; 

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {

        unordered_map<int, unordered_set<int>> adj;

        for (vector<int> road : roads)
        {
            int c1 = road[0];
            int c2 = road[1];

            adj[c1].insert(c2);
            adj[c2].insert(c1);
        }

        int result = INT_MIN;

        for (auto p : adj)
        {
            int first = p.first;

            for (auto q : adj)
            {
                int second = q.first;
                unordered_set<int> st = q.second;

                if (first == second)
                    continue;

                int size = adj[first].size() ; 

                if (st.find(first) != st.end())
                {
                    size += st.size() - 1 ; 
                }else{
                    size += st.size() ; 
                }

                result = max(result , size) ; 
            }
        }

        return result == INT_MIN ? 0 : result ;
    }
};

int main()
{
    Solution sol;

    int n1 = 4;
    vector<vector<int>> roads1 = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    cout << "Test Case 1 Output: "
         << sol.maximalNetworkRank(n1, roads1)
         << " | Expected: 4" << endl;

    int n2 = 5;
    vector<vector<int>> roads2 = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    cout << "Test Case 2 Output: "
         << sol.maximalNetworkRank(n2, roads2)
         << " | Expected: 5" << endl;

    int n3 = 8;
    vector<vector<int>> roads3 = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
    cout << "Test Case 3 Output: "
         << sol.maximalNetworkRank(n3, roads3)
         << " | Expected: 5" << endl;

    return 0;
}
