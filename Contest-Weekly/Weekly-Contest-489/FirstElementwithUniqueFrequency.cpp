#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums){

        int n = nums.size() ; 

        unordered_map<int , int >freq , freqCount ; 


        for(int num : nums){
            freq[num] ++ ; 
        }

        for(pair<int , int >p : freq){

            int first = p.first ; 
            int second = p.second ; 

            freqCount[second] ++ ; 
        }

        int result = -1  ; 

        for(int num : nums){

           if(freqCount[freq[num]] == 1){
            result = num ; 
            break;
           }

        }

        return result ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {20, 10, 30, 30};
    cout << "Output: " << sol.firstUniqueFreq(nums1)
         << " | Expected: 30" << endl;

    // Example 2
    vector<int> nums2 = {20, 20, 10, 30, 30, 30};
    cout << "Output: " << sol.firstUniqueFreq(nums2)
         << " | Expected: 20" << endl;

    // Example 3
    vector<int> nums3 = {10, 10, 20, 20};
    cout << "Output: " << sol.firstUniqueFreq(nums3)
         << " | Expected: -1" << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

