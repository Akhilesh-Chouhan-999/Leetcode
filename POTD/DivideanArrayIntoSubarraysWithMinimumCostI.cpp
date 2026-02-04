#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int n = nums.size() ;

        int result = 0 ;
        int min1 = INT_MAX ; 
        int min2 = INT_MAX ; 

        for(int i = 1 ; i < n ; i ++){

            if(nums[i] < min1){
                min2 = min1 ; 
                min1 = nums[i] ; 
            }else{
                min2 = min(min2 , nums[i]) ; 
            }
        }

        return nums[0] + min1 + min2 ; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3, 12},
        {5, 4, 3},
        {10, 3, 1, 1},
        {7, 1, 5, 2, 6}
    };

    for (auto &nums : testCases) {
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << "\nMinimum Cost = " << sol.minimumCost(nums) << "\n\n";
    }

    return 0;
}
