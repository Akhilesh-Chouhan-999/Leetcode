#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {

        int n = nums.size();
        int i = 0;
        int j = 0;

        int result = INT_MAX;
        unordered_map<int, int> mpp;

        int sum = 0;

        while (j < n)
        {

            if (mpp.count(nums[j]) == false)
            {
                sum += nums[j];
            }

            mpp[nums[j]] = j;

            while (sum >= k && i < n)
            {

                result = min(result, j - i + 1);

                if (mpp[nums[i]] == i)
                {
                    sum -= nums[i];

                    mpp.erase(nums[i]);
                }

                i++;
            }

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 2, 3, 1};
    int k1 = 4;
    cout << "Example 1\n";
    cout << "Input: nums = [2,2,3,1], k = 4\n";
    cout << "Output: " << sol.minLength(nums1, k1) << endl;
    cout << "Expected: 2\n\n";

    // Example 2
    vector<int> nums2 = {3, 2, 3, 4};
    int k2 = 5;
    cout << "Example 2\n";
    cout << "Input: nums = [3,2,3,4], k = 5\n";
    cout << "Output: " << sol.minLength(nums2, k2) << endl;
    cout << "Expected: 2\n\n";

    // Example 3
    vector<int> nums3 = {5, 5, 4};
    int k3 = 5;
    cout << "Example 3\n";
    cout << "Input: nums = [5,5,4], k = 5\n";
    cout << "Output: " << sol.minLength(nums3, k3) << endl;
    cout << "Expected: 1\n";

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)