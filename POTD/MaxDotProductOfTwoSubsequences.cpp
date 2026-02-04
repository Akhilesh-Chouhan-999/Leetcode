/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxProduct = INT_MIN ;

      void solve(vector<int>&nums1 , vector<int>&nums2 , int m , int n , int i , int j , int currProduct){

        if( i == m || j == n){
            maxProduct = max(maxProduct , currProduct) ;
            cout << maxProduct << endl;
            return  ;
        }

        int product = nums1[i] * nums2[j] ;
        int take ;

        if(currProduct == INT_MIN)
        take = product ;
        else
        take = max(currProduct + product , product) ;


         solve(nums1 , nums2 , m ,  n , i + 1 , j + 1, take) ;

         solve(nums1 , nums2 , m , n , i + 1 , j , currProduct) ;

         solve(nums1 , nums2 , m , n , i , j + 1 , currProduct ) ;


         return ;


      }


    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size() ;
        int n = nums2.size() ;
        int currSum = INT_MIN                           ;

        solve(nums1 , nums2 , m , n , 0 , 0 ,  currSum ) ;

        return maxProduct ;



    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1_1 = {2, 1, -2, 5};
    vector<int> nums2_1 = {3, 0, -6};
    cout << "Output 1: " << sol.maxDotProduct(nums1_1, nums2_1) << endl;

    // Test case 2
    vector<int> nums1_2 = {3, -2};
    vector<int> nums2_2 = {2, -6, 7};
    cout << "Output 2: " << sol.maxDotProduct(nums1_2, nums2_2) << endl;


    return 0;
}


// Time Complexity  O( 3 ^ ( m + n ))
// Space Complexity : O( m + n )

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct = INT_MIN;

    void solve(vector<int> &nums1, vector<int> &nums2, int m, int n, int i, int j, int currProduct)
    {

        if (i == m || j == n)
        {
            maxProduct = max(maxProduct, currProduct);
            return;
        }

        int product = nums1[i] * nums2[j];
        int take;

        if (currProduct == INT_MIN)
            take = product;
        else
            take = max(currProduct + product, product);

        solve(nums1, nums2, m, n, i + 1, j + 1, take);

        solve(nums1, nums2, m, n, i + 1, j, currProduct);

        solve(nums1, nums2, m, n, i, j + 1, currProduct);

        return;
    }

    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {

        int m = nums1.size();
        int n = nums2.size();
        int currSum = INT_MIN;

        solve(nums1, nums2, m, n, 0, 0, currSum);

        return maxProduct;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1_1 = {2, 1, -2, 5};
    vector<int> nums2_1 = {3, 0, -6};
    cout << "Output 1: " << sol.maxDotProduct(nums1_1, nums2_1) << endl;

    // Test case 2
    vector<int> nums1_2 = {3, -2};
    vector<int> nums2_2 = {2, -6, 7};
    cout << "Output 2: " << sol.maxDotProduct(nums1_2, nums2_2) << endl;

    return 0;
}

// Time Complexity  O( 3 ^ ( m + n ))
// Space Complexity : O( m + n )