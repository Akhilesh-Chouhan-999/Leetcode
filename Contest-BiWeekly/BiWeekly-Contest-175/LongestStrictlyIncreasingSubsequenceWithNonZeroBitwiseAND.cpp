#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size() ; 

        int result = INT_MIN ; 

        for(int bit = 0 ; bit <= 30 ; bit ++){
            
            vector<int>temp ; 

            for(int &x : nums){
                if(( x & ( 1 << bit)) == 0) 
                continue;

                auto it = lower_bound(begin(temp) , end(temp) , x) ; 

                if(it == temp.end()) 
                temp.push_back(x) ;
                else
                *it = x ; 
                
            }

            result = max(result , (int)temp.size()) ; 

        }
    
         return result ; 
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {5, 4, 7};
    vector<int> test2 = {2, 3, 6};
    vector<int> test3 = {0, 1};

    cout << sol.longestSubsequence(test1) << endl; 
    cout << sol.longestSubsequence(test2) << endl; 
    cout << sol.longestSubsequence(test3) << endl; 

    return 0;
}