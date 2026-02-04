/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int size = nums.size() / 2 ; 

        unordered_map<int , int>mpp ; 

        for(int &num : nums){
            mpp[num] ++ ; 
        }

        for(pair<int , int>p : mpp){
            int num = p.first ; 
            int freq = p.second ; 

            if(freq >= size) 
            return  num ; 
        }

        return -1 ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 3};
    cout << "Output: " << sol.repeatedNTimes(nums1) << " (Expected: 3)" << endl;

    // Example 2
    vector<int> nums2 = {2, 1, 2, 5, 3, 2};
    cout << "Output: " << sol.repeatedNTimes(nums2) << " (Expected: 2)" << endl;

    // Example 3
    vector<int> nums3 = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << "Output: " << sol.repeatedNTimes(nums3) << " (Expected: 5)" << endl;

    return 0;
}
Time Complexity : O(n)
Space Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size() ; 

        for(int i = 2 ; i < n ; i ++ ){
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2]){
                return nums[i] ; 
            }
        }
        
        return nums.back() ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 3};
    cout << "Output: " << sol.repeatedNTimes(nums1) << " (Expected: 3)" << endl;

    // Example 2
    vector<int> nums2 = {2, 1, 2, 5, 3, 2};
    cout << "Output: " << sol.repeatedNTimes(nums2) << " (Expected: 2)" << endl;

    // Example 3
    vector<int> nums3 = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << "Output: " << sol.repeatedNTimes(nums3) << " (Expected: 5)" << endl;

    return 0;
}
