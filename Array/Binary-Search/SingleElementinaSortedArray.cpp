

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      
         int n = nums.size() ; 

        

         for(int i = 1  ; i < n ; i += 2){

            if(nums[i] != nums[i-1])
            {
                return nums[i-1] ; 
            }

         }


         return nums.back(); 
    }
};

int main() {
    Solution sol;

    // ----- Test Case 1 -----
    vector<int> t1 = {1,1,2,3,3,4,4,8,8};
    cout << "Test Case 1 Output: " << sol.singleNonDuplicate(t1) << endl;

    // ----- Test Case 2 -----
    vector<int> t2 = {3,3,7,7,10,11,11};
    cout << "Test Case 2 Output: " << sol.singleNonDuplicate(t2) << endl;

    // ----- Test Case 3 -----
    vector<int> t3 = {5};
    cout << "Test Case 3 Output: " << sol.singleNonDuplicate(t3) << endl;

    // ----- Test Case 4 -----
    vector<int> t4 = {2,2,4,4,6};
    cout << "Test Case 4 Output: " << sol.singleNonDuplicate(t4) << endl;

    // ----- Test Case 5 -----
    vector<int> t5 = {1,1,3,3,4,4,9,9,10};
    cout << "Test Case 5 Output: " << sol.singleNonDuplicate(t5) << endl;

    return 0;
}
    Time Compleixity : O(n)
    */

    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      
        
        int n = nums.size() ; 

        int low = 0 ; 
        int high = n - 1 ; 


        while(low < high){

            int mid = low + ( high - low ) / 2 ; 

            if(mid % 2  == 0 )
            {
                if(nums[mid] == nums[mid-1])
                {
                    high = mid - 2 ; 
                }
                else 
                {
                   low = mid ; 
                }
            }
            else
            {
                if(nums[mid] == nums[mid+1])
                {
                    high = mid - 1 ; 
                }
                else
                {
                    low = mid + 1  ; 
                }


            }
        }

        return nums[low] ;

    }
};

int main() {
    Solution sol;

    // ----- Test Case 1 -----
    vector<int> t1 = {1,1,2,3,3,4,4,8,8};
    cout << "Test Case 1 Output: " << sol.singleNonDuplicate(t1) << endl;

    // ----- Test Case 2 -----
    vector<int> t2 = {3,3,7,7,10,11,11};
    cout << "Test Case 2 Output: " << sol.singleNonDuplicate(t2) << endl;

    // ----- Test Case 3 -----
    vector<int> t3 = {5};
    cout << "Test Case 3 Output: " << sol.singleNonDuplicate(t3) << endl;

    // ----- Test Case 4 -----
    vector<int> t4 = {2,2,4,4,6};
    cout << "Test Case 4 Output: " << sol.singleNonDuplicate(t4) << endl;

    // ----- Test Case 5 -----
    vector<int> t5 = {1,1,3,3,4,4,9,9,10};
    cout << "Test Case 5 Output: " << sol.singleNonDuplicate(t5) << endl;

    return 0;
}