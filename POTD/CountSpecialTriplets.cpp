/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7 ;

        int n = nums.size() ;
        int result = 0 ;

        for(int i = 0 ; i < n ; i ++){

            for(int j = i + 1 ; j < n ; j ++){

                for(int k = j + 1 ; k < n ; k ++){

                    if(nums[i] == 2*nums[j] && nums[k] == 2*nums[j]){
                        result ++ ;
                    }
                }
            }
        }

       return result % MOD ;
    }
};

int main() {
        Solution obj;

    vector<int> nums = {6,3,6};


    int ans = obj.specialTriplets(nums);
    cout << ans << endl;



    return 0;
}

Time Complexity : O(n ^ 3)




#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        int MOD = 1e9 + 7;

        int n = nums.size();
        int result = 0;

        unordered_map<int, int> mpp_left;
        unordered_map<int, int> mpp_right;

        for (int &num : nums)
        {
            mpp_right[num]++;
        }

        for (int &num : nums)
        {

            --mpp_right[num];

            if (mpp_right[num] == 0)
                mpp_right.erase(num);

            if (mpp_left.count(2 * num) && mpp_right.count(2 * num))
            {
                int left = mpp_left[2*num]  ;
                int right = mpp_right[2*num] ;

                result = (( 1LL* left * right) + result) % MOD ; 
            }

            mpp_left[num]++;
        }

        return result % MOD;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3, 4, 6},
        {2, 4, 2, 4, 2},
        {5, 10, 5, 20, 10},
        {1, 1, 2, 2, 4, 4},
        {3, 6, 3, 6, 12}};

    for (int i = 0; i < tests.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << sol.specialTriplets(tests[i]) << endl;
    }

    return 0;
}

Time Complexity : O(n)
Space Complexity : O(n)
But Two Pass Solution . 


*/



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
       const int MOD = 1e9 + 7;

        unordered_map<int , int>valid_i ; 
        unordered_map<int , int>valid_j ;

        int result = 0 ; 


        for(int &num : nums){   
            
            if(num % 2 == 0 && valid_j.count(num/2)){
                result = (valid_j[num/2] + result) % MOD ;  
            }
            
            if(valid_i.count(2*num)){
                valid_j[num] += valid_i[2*num] ;
            }

            valid_i[num] ++ ; 
        }

        return result ; 
      
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3, 4, 6},
        {2, 4, 2, 4, 2},
        {5, 10, 5, 20, 10},
        {1, 1, 2, 2, 4, 4},
        {3, 6, 3, 6, 12}};

    for (int i = 0; i < tests.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << sol.specialTriplets(tests[i]) << endl;
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
// Single Pass Solution . 