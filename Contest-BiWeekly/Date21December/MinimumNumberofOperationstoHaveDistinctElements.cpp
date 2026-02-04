#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size() ;
        int index = -1 ; 
        unordered_map<int , int>mpp ; 

        for(int i = n - 1 ; i >= 0 ; i --){
            if(mpp.count(nums[i])){
                index = i ; 
                break ; 
            }


            mpp[nums[i]] = i ; 
        }

        if(index == -1) return 0 ; 
    

        return (index + 3) / 3 ; 
       
    }
};


int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 8, 3, 6, 5, 8},
        {2, 2},
        {4, 3, 5, 1, 2}
    };

    vector<int> expectedOutput = {1, 1, 0};

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        int result = sol.minOperations(nums);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expectedOutput[i] << endl;
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

