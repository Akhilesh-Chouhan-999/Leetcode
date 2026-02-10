/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums){
        
        int n = nums.size() ;

        int result = 0 ; 

        for(int i = 0 ; i < n ; i ++){

             unordered_set<int>countDistinctOdd ; 
             unordered_set<int>countDistinctEven ;
            
               for(int j = i ; j < n ; j ++ ){

                  unordered_set<int>countDistinctOdd ; 
                  unordered_set<int>countDistinctEven ;


                for(int k = i ; k <= j ; k ++ ){

                    if(nums[k] % 2 == 0)
                    countDistinctEven.insert(nums[k]) ; 
                    else
                    countDistinctOdd.insert(nums[k]) ; 

                }



                if(countDistinctEven.size() == countDistinctOdd.size())
                    result = max(result , j - i + 1 )  ; 
            }
        }

        return result ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> nums1 = {2, 5, 4, 3};
    cout << "Output: " << sol.longestBalanced(nums1)
         << " | Expected: 4" << endl;

    // ---------- Example 2 ----------
    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << "Output: " << sol.longestBalanced(nums2)
         << " | Expected: 5" << endl;

    // ---------- Example 3 ----------
    vector<int> nums3 = {1, 2, 3, 2};
    cout << "Output: " << sol.longestBalanced(nums3)
         << " | Expected: 3" << endl;

    return 0;
}
Time Complexity : O( n ^ 3)
Space Complexity : O(n)

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums){
        
        int n = nums.size() ;

        int result = 0 ; 

        for(int i = 0 ; i < n ; i ++){

             unordered_set<int>countDistinctOdd ; 
             unordered_set<int>countDistinctEven ;
            
              for(int j = i ; j < n ; j ++ ){

                nums[j] % 2 == 0 ? countDistinctEven.insert(nums[j]) : countDistinctOdd.insert(nums[j]) ; 

                if(countDistinctEven.size() == countDistinctOdd.size())
                result = max(result , j - i + 1 ) ; 
                  
            }
        }

        return result ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> nums1 = {2, 5, 4, 3};
    cout << "Output: " << sol.longestBalanced(nums1)
         << " | Expected: 4" << endl;

    // ---------- Example 2 ----------
    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << "Output: " << sol.longestBalanced(nums2)
         << " | Expected: 5" << endl;

    // ---------- Example 3 ----------
    vector<int> nums3 = {1, 2, 3, 2};
    cout << "Output: " << sol.longestBalanced(nums3)
         << " | Expected: 3" << endl;

    return 0;
}

// Time Complexity : O( n ^ 2)
// Space Complexity : O(n)

