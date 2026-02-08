#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n = nums.size() ;

        vector<int>result( n , -1) ; 

        for(int i = 0 ; i < n ; i ++){
            
            if(nums[i] == 0 ){
            result[i] = nums[i] ;
             }

            else if(nums[i] > 0){
                int index = ( i + nums[i] ) %n ;
                result[i] = nums[index] ; 
            }
            
            else{
                int index = i + nums[i]  ;  
                
                if(index < 0)
                index =( index % n + n ) % n; 
                

                result[i] = nums[index] ; 

            }
 
        }

        return result ; 


    }
};


int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, -2, 1, 1};
    vector<int> expected1 = {1, 1, 1, 3};

    vector<int> result1 = sol.constructTransformedArray(nums1);

    cout << "Test Case 1 Output: ";
    for (int x : result1) cout << x << " ";
    cout << "\nExpected Output: ";
    for (int x : expected1) cout << x << " ";
    cout << "\n\n";

    // Test case 2
    vector<int> nums2 = {-1, 4, -1};
    vector<int> expected2 = {-1, -1, 4};

    vector<int> result2 = sol.constructTransformedArray(nums2);

    cout << "Test Case 2 Output: ";
    for (int x : result2) cout << x << " ";
    cout << "\nExpected Output: ";
    for (int x : expected2) cout << x << " ";
    cout << "\n";

    return 0;
}
