#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using ll = long long;
    long long maximumScore(vector<int> &nums, string s)
    {

        int n = nums.size();
        ll result = 0;

        int cntOnes = 0;
        int lastPostion = -1;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (ch == '1')
            {
                lastPostion = i;
                cntOnes++;
            }
        }

        if (cntOnes == 0)
            return 0;

        priority_queue<int> max_heap;

        for (int i = 0; i <= lastPostion; i++)
        {

            max_heap.push(nums[i]);

            if (s[i] == '1')
            {
                result += max_heap.top();
                max_heap.pop();
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> numsTestCases = {
        {2, 1, 5, 2, 3},
        {4, 7, 2, 9}};

    vector<string> sTestCases = {
        "01010",
        "0000"};

    vector<long long> expectedOutput = {
        7,
        0};

    for (int i = 0; i < numsTestCases.size(); i++)
    {
        long long result = sol.maximumScore(numsTestCases[i], sTestCases[i]);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expectedOutput[i] << endl;
    }

    return 0;
}
 
// Time Complexity :     O(n*log(n))
// Space Complexity :   O(n)