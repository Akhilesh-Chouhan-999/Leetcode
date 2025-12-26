
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size() ; 


        int result = 1 ; 

        int l = 0 ; 
        int mask = nums[0] ; 

        for(int r = 1 ; r < n ; r ++ ){

            while( ( mask & nums[l]) != 0  ){
                mask = mask ^ nums[l] ; 
                l ++ ; 
            }
            
            mask |= nums[r] ;             
            result = max(result , r - l  + 1) ;
        }

        return result ; 
    }
};



int main() {
        
    vector<int> nums = { 1,3,8,48,10 } ;
    Solution obj;
    cout << obj.longestNiceSubarray(nums) << endl;

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1)


/*
OR (|): Used to track presence of bits; safe without conditions
XOR (^): Used to remove bits; safe only when bit overlap is guaranteed not to exist
*/