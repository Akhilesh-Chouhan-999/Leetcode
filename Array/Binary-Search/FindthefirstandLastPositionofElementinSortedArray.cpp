/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
 
        
        int n = nums.size() ; 

        int firstPos = -1 ; 
        int lastPos = -1 ; 

        for(int i = 0 ; i < n ; i ++ )
        {
            int element = nums[i] ; 

            if(element == target)
            {
                if(firstPos == -1) firstPos = i ; 
                lastPos = i ; 
            }
        }

        if(firstPos == -1)
        return {-1, -1};

        return { firstPos , lastPos} ; 
    }
};

void runTest(vector<int> nums, int target, Solution& sol) {
    vector<int> result = sol.searchRange(nums, target);

    cout << "nums = [ ";
    for (int x : nums) cout << x << " ";
    cout << "]  target = " << target << "  ->  ";

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    runTest({5, 7, 7, 8, 8, 10}, 8, sol);

    // Test case 2
    runTest({5, 7, 7, 8, 8, 10}, 6, sol);

    // Test case 3
    runTest({}, 3, sol);

    // Test case 4
    runTest({1}, 1, sol);

    // Test case 5
    runTest({2, 2, 2, 2, 2}, 2, sol);

    return 0;
}


Time Complexity :O(n)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int binarySearchLastOCcurence(vector<int>&nums , int target){

        int size = nums.size() ; 

        int start = 0 ; 
        int end = size - 1  ; 
        int lastOccurence = -1 ; 

        int mid  ; 
        while(start <= end)
        {
            mid = start + (end - start) / 2 ; 

            if(nums[mid] == target)
            {
                lastOccurence = mid ; 
                start = mid + 1 ; 
            }
            else if(nums[mid] < target)
            {
                start = mid + 1 ; 
            }
            else
            {
                end = mid - 1 ; 
            }
        }

        return lastOccurence ; 
     }
    int binarySearchFirstOccurence(vector<int>&nums , int target){

        int size = nums.size() ; 

        int start = 0 ; 
        int end = size  - 1 ; 
        int firstOccurence = -1 ; 

        while(start <= end){

            int mid = start + ( end - start ) / 2 ; 

            if(nums[mid] == target)
            {
                firstOccurence = mid ; 
                end = mid - 1 ; 
            }

            else if(nums[mid] < target)
            {
                start = mid + 1 ; 
            }
            else
            {
                end = mid - 1 ; 
            }
        }


        return firstOccurence ; 
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int firstOccurence = binarySearchFirstOccurence(nums , target) ; 
        int lastOccurence = binarySearchLastOCcurence(nums , target) ; 

        return {firstOccurence , lastOccurence} ; 

    }
};

void runTest(vector<int> nums, int target, Solution& sol) {
    vector<int> result = sol.searchRange(nums, target);

    cout << "nums = [ ";
    for (int x : nums) cout << x << " ";
    cout << "]  target = " << target << "  ->  ";

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    runTest({5, 7, 7, 8, 8, 10}, 8, sol);

    // Test case 2
    runTest({5, 7, 7, 8, 8, 10}, 6, sol);

    // Test case 3
    runTest({}, 3, sol);

    // Test case 4
    runTest({1}, 1, sol);

    // Test case 5
    runTest({2, 2, 2, 2, 2}, 2, sol);

    return 0;
}

// Time Complexity : O(log(n))