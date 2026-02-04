#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int size = nums.size() ; 

        int start = 0 ; 
        int end = size - 1 ; 

        while(start <= end){

            int mid = start + ( end - start) / 2 ; 

            if(nums[mid] == target) return true ; 

            if(nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start  ++ ; 
                end -- ; 
                continue ; 
            }

            if(nums[start] <= nums[mid]){

                if(nums[start] <= target && target < nums[mid]) {
                    end = mid ; 
                }
                else
                start = mid +  1; 
            }
             else if(nums[mid] <= nums[end]) {

                if(nums[mid] < target && target <= nums[end]) {
                    start = mid ; 
                }
                else
                end = mid - 1 ; 
            }
        }
        
        return false;
    }
};

int main() {
    Solution s;

    // 5 testcases
    vector<vector<int>> tests = {
        {2,5,6,0,0,1,2},
        {1,0,1,1,1},
        {1,1,1,3,1},
        {3,1},
        {1,3,1,1}
    };

    vector<int> targets = {0, 0, 3, 3, 3};

    for (int i = 0; i < tests.size(); i++) {
        cout << "Testcase " << i+1 << ": ";
        for (int x : tests[i]) cout << x << " ";

        cout << "\nTarget: " << targets[i];

        bool result = s.search(tests[i], targets[i]);

        cout << "\nResult: " << (result ? "true" : "false") << "\n\n";
    }

    return 0;
}
