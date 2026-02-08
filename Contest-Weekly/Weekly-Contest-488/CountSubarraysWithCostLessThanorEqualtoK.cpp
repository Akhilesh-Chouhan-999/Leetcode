#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k){

        int n = nums.size() ; 

        int i = 0  ; 
        int j = 0 ; 
        long long result = 0 ; 

        deque<int>minDq , maxDq ; 

        while(j < n){

            int curr = nums[j]  ; 

            // MaxHeap
            while( !maxDq.empty() && (curr >= nums[maxDq.back()] ) )
            maxDq.pop_back() ; 
            maxDq.push_back(j) ; 


            // MinHeap
            while ( !minDq.empty() && (curr <= nums[minDq.back()]) )
                minDq.pop_back() ; 
                minDq.push_back(j) ; 


            while(!minDq.empty() && !maxDq.empty() &&  (nums[maxDq.front()] - nums[minDq.front()])*(j - i + 1)  > k ){

                if(minDq.front() <= i ) 
                minDq.pop_front() ; 

                if(maxDq.front() <= i )
                maxDq.pop_front() ; 

                i ++ ; 

            }

            result += ( j - i + 1) ;
            
            j ++ ; 

        }


        return result ; 
        
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> nums1 = {1, 3, 2};
    long long k1 = 4;
    cout << "Output: " << sol.countSubarrays(nums1, k1)
         << " | Expected: 5" << endl;

    // ---------- Example 2 ----------
    vector<int> nums2 = {5, 5, 5, 5};
    long long k2 = 0;
    cout << "Output: " << sol.countSubarrays(nums2, k2)
         << " | Expected: 10" << endl;

    // ---------- Example 3 ----------
    vector<int> nums3 = {1, 2, 3};
    long long k3 = 0;
    cout << "Output: " << sol.countSubarrays(nums3, k3)
         << " | Expected: 3" << endl;

    return 0;
}
