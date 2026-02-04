/*


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findMin(vector<int>& nums) {
        
    int n = nums.size() ; 
    
    int mini = INT_MAX ; 
    
    for(int &num : nums)
    {
            mini = min(mini , num) ; 
        }

        if(mini == INT_MAX)
        return -1;
        
        return mini ; 
        
    }
};
// Time complexity : O(n)

void runTest(vector<int> nums, Solution& sol) {
    int ans = sol.findMin(nums);
    
    cout << "nums = [ ";
    for (int x : nums) cout << x << " ";
    cout << "]  -> Min = " << ans << endl;
}

int main() {
    Solution sol;
    
    // Test case 1
    runTest({3, 4, 5, 1, 2}, sol);
    
    // Test case 2
    runTest({4, 5, 6, 7, 0, 1, 2}, sol);
    
    // Test case 3
    runTest({11, 13, 15, 17}, sol);
    
    // Test case 4
    runTest({2, 1}, sol);
    
    // Test case 5
    runTest({1}, sol);
    
    return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size() ; 

        int left = 0 ; 
        int right = n - 1 ; 
        int mini = INT_MAX ; 

        while(left <= right){

            int mid = left + (right - left) / 2 ; 

            if(nums[left] <= nums[mid])
            {
                mini = min(mini , nums[left]) ; 
                left = mid + 1 ; 
            }
            else 
            {
                mini = min(mini , nums[mid]) ; 
                right = mid - 1 ; 
            }


        }

        return mini ; 
    }
};


void runTest(vector<int> nums, Solution& sol) {
    int ans = sol.findMin(nums);

    cout << "nums = [ ";
    for (int x : nums) cout << x << " ";
    cout << "]  -> Min = " << ans << endl;
}

int main() {
    Solution sol;

    // Test case 1
    runTest({3, 4, 5, 1, 2}, sol);

    // Test case 2
    runTest({4, 5, 6, 7, 0, 1, 2}, sol);

    // Test case 3
    runTest({11, 13, 15, 17}, sol);

    // Test case 4
    runTest({2, 1}, sol);

    // Test case 5
    runTest({1}, sol);

    return 0;
}


// Time Complexity : O(log(n))