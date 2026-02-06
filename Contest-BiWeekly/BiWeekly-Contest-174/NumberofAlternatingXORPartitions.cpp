/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n   ; 
    int t1 , t2  ;
    const int MOD = 1000000007 ;  
    vector<vector<long long>>dp ; 

    long long solve(int i , bool flag , vector<int>&nums){

        if( i == n ){
            return 1 ; 
        }

        if(dp[i][flag] != -1) 
        return dp[i][flag] ; 

        long long ways = 0 ; 
        int xr = 0 ; 

        for(int j = i ; j < n ; j ++ ){

            xr = xr ^ nums[j] ; 

            int target = ( flag ? t1 : t2) ; 

            if(target == xr){
                ways = ( ways + solve( j + 1 , !flag , nums)) % MOD ; 
            }
        }

        return dp[i][flag] = ways ; 
    }


    int alternatingXOR(vector<int>& nums, int target1, int target2) {

        n = nums.size() ;
        t1 = target1 ; 
        t2 = target2 ; 

        dp.assign(n , vector<long long>(2 , -1)) ;

        // true -- starts with t1
        // false -- starts with t2 

        return solve( 0 , true , nums) ; 
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int target1_1 = 4;
    int target2_1 = 6;
    cout << "Output 1: "
         << sol.alternatingXOR(nums1, target1_1, target2_1)
         << endl;

    // Test Case 2
    vector<int> nums2 = {5, 5, 5};
    int target1_2 = 5;
    int target2_2 = 0;
    cout << "Output 2: "
         << sol.alternatingXOR(nums2, target1_2, target2_2)
         << endl;

    // Test Case 3 (single block case)
    vector<int> nums3 = {7};
    int target1_3 = 7;
    int target2_3 = 3;
    cout << "Output 3: "
         << sol.alternatingXOR(nums3, target1_3, target2_3)
         << endl;

    return 0;
}


 Time Complexity : Total  = (number of states) × (work per state)
                          = (2n) × O(n)
                          = O(n²)
 Space Complexity : O(n)

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n   ; 
    int t1 , t2  ;
    const int MOD = 1000000007 ;  
    vector<vector<long long>>dp ; 

    long long solve(int i , bool flag , vector<int>&nums){

        if( i == n ){
            return 1 ; 
        }

        if(dp[i][flag] != -1) 
        return dp[i][flag] ; 

        long long ways = 0 ; 
        int xr = 0 ; 

        for(int j = i ; j < n ; j ++ ){

            xr = xr ^ nums[j] ; 

            int target = ( flag ? t1 : t2) ; 

            if(target == xr){
                ways = ( ways + solve( j + 1 , !flag , nums)) % MOD ; 
            }
        }

        return dp[i][flag] = ways ; 
    }


    int alternatingXOR(vector<int>& nums, int target1, int target2) {

        n = nums.size() ;
        t1 = target1 ; 
        t2 = target2 ; 

        dp.assign(n , vector<long long>(2 , -1)) ;

        // true -- starts with t1
        // false -- starts with t2 

        return solve( 0 , true , nums) ; 
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int target1_1 = 4;
    int target2_1 = 6;
    cout << "Output 1: "
         << sol.alternatingXOR(nums1, target1_1, target2_1)
         << endl;

    // Test Case 2
    vector<int> nums2 = {5, 5, 5};
    int target1_2 = 5;
    int target2_2 = 0;
    cout << "Output 2: "
         << sol.alternatingXOR(nums2, target1_2, target2_2)
         << endl;

    // Test Case 3 (single block case)
    vector<int> nums3 = {7};
    int target1_3 = 7;
    int target2_3 = 3;
    cout << "Output 3: "
         << sol.alternatingXOR(nums3, target1_3, target2_3)
         << endl;

    return 0;
}
