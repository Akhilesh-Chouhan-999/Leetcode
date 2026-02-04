#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int n = nums.size() ; 

        int index = 0 ; 

        while( index < n - 1  && nums[index] < nums[index + 1]) index ++ ;

        if(index == 0 || index >= n - 1 ) return false ;

        while(index < n - 1 && nums[index] > nums[index + 1]) index ++ ; 

        if(index >= n - 1 ) return false ; 

        while(index < n - 1 && nums[index] < nums[index+1]) index ++ ; 

        if(index == n - 1) 
        return true ; 


        return false ; 
    }
};


int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 3, 5, 4, 2, 6},   // true
        {2, 1, 3},           // false
        {1, 2, 3, 2, 1, 2},  // true
        {1, 2, 1, 2},        // false
        {5, 6, 7, 4, 3, 8}   // true
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        cout << sol.isTrionic(testCases[i]) << endl;
    }

    return 0;
}