#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int n = nums.size() ;

        int firstPlayer = 0 ; 
        int secondPlayer = 0 ; 

        bool isActive = true ; 


        int i = 0 ; 

        while( i < n ){

            if((nums[i] % 2 == 1 ) ){
                isActive = !isActive ; 
            }

            if( ( (i + 1)  % 6 == 0)){
                isActive = !isActive ; 
            }

            if(isActive)
            firstPlayer += nums[i] ; 
            
            else
            secondPlayer += nums[i] ;  

            i ++ ; 
        }

        return firstPlayer - secondPlayer ; 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Output: " << sol.scoreDifference(nums1)
         << " | Expected: 0" << endl;

    // Example 2
    vector<int> nums2 = {2, 4, 2, 1, 2, 1};
    cout << "Output: " << sol.scoreDifference(nums2)
         << " | Expected: 4" << endl;

    // Example 3
    vector<int> nums3 = {1};
    cout << "Output: " << sol.scoreDifference(nums3)
         << " | Expected: -1" << endl;

    return 0;
}