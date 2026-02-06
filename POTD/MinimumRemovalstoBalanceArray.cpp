#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        int n = nums.size() ; 
        sort(begin(nums) , end(nums)) ;

        int i = 0 ; 
        int j = 0 ; 

        int best = 0 ; 


        while( j < n ){

            if(nums[j] > k * nums[i]){
                i ++ ; 
                continue;
            }
            
            best = max(best , j  - i ) ;  
            
            j ++ ; 
        }

        return n - best ; 

    }
};


int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3 , 5 , 8 , 12},
        {1, 6, 2, 9},
        {4, 6},
        {1},
        {1, 100, 200, 300}
    };

    vector<int> kValues = {2, 3, 2, 10, 2};
    vector<int> expected = {4, 2, 0, 0, 3};

    for (int i = 0; i < testCases.size(); i++) {
        int result = sol.minRemoval(testCases[i], kValues[i]);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Expected: " << expected[i] << "\n";
        cout << "Result  : " << result << "\n";
    }

    return 0;
}