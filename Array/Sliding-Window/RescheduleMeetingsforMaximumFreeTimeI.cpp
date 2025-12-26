#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {

        int n = startTime.size();

        vector<int> spaceArray;

        int prevEndTime = 0;

        for (int t = 0; t < n; t++)
        {
            int currStartTime = startTime[t];
            int currEndTime = endTime[t];

            spaceArray.push_back(currStartTime - prevEndTime);

            prevEndTime = currEndTime;
        }
            
        spaceArray.push_back(eventTime - prevEndTime);
        

        int result = 0;
        int i = 0;

        int sum = 0;
        for (int j = 0; j < spaceArray.size(); j++)
        {
            sum += spaceArray[j];

            while (j - i + 1 > k + 1)
            {

                sum -= spaceArray[i];
                i++;
            }

            result = max(result, sum);
        }

        return result;
    }
};

int main()
{
    Solution obj;

    struct TestCase
    {
        int eventTime;
        int k;
        vector<int> startTime;
        vector<int> endTime;
        int expected;
    };

    vector<TestCase> tests = {

        // ---- Given Examples ----
        {5, 1, {1, 3}, {2, 5}, 2},
        {10, 1, {0, 2, 9}, {1, 4, 10}, 6},
        {5, 2, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}, 0},

        // ---- Additional Test Cases ----

        // Single meeting
        {10, 1, {2}, {5}, 7},

        // No meetings
        {8, 0, {}, {}, 8},

        // k = 0 (no rescheduling allowed)
        {10, 0, {2, 5}, {3, 6}, 4},

        // Meetings already tightly packed
        {6, 1, {0, 1, 2}, {1, 2, 3}, 3},

        // Large free space in middle
        {20, 2, {1, 2, 15}, {2, 3, 16}, 12},

        // All meetings cover full event
        {5, 3, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}, 0}};

    for (int i = 0; i < tests.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Output = "
             << obj.maxFreeTime(
                    tests[i].eventTime,
                    tests[i].k,
                    tests[i].startTime,
                    tests[i].endTime)
             << "\nExpected = " << tests[i].expected << "\n\n";
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)