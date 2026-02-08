#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size() ; 
        double average = 0 ;
        int sum = 0 ; 

        for(int &num : nums){
            sum += num ; 
        }

        average = sum ; 

        
        int cnt = 0 ; 

        sum = 0 ; 

        for(int i = 0  ; i < n - 1 ; i ++){

            sum += nums[i] ;
            
            if( nums[i] > (average - sum ) / (1.0 * (n - i - 1)) )
                cnt ++ ; 

        }

        return cnt ; 
        
        
    }
};
int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> nums1 = {5, 4, 3};
    cout << "Output: " << sol.dominantIndices(nums1)
         << " | Expected: 2" << endl;

    // ---------- Example 2 ----------
    vector<int> nums2 = {4, 1, 2};
    cout << "Output: " << sol.dominantIndices(nums2)
         << " | Expected: 1" << endl;

    return 0;
}
