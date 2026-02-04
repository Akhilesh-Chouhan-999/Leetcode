#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<pair<int , int>>&temp , bitset<32> bs , int num){

        int idx = 31 ; 

        while(idx >= 0 && bs[idx] == 0) idx -- ; 

        int i = 0 ; 
        int j = idx ; 

        while(i < j){
            int x = bs[i] ; 
            int y = bs[j] ; 
            bs[i] = y  ; 
            bs[j] = x ; 

            i++ ; 
            j -- ; 
        }



        int decimal = static_cast<int>(bs.to_ullong());

        temp.push_back({decimal ,  num}) ;
    
    }
    vector<int> sortByReflection(vector<int>& nums) {

        int n = nums.size() ; 

        vector<pair<int , int>>temp ; 

        for(int &num : nums){

            bitset<32>bs(num) ; 
            solve(temp , bs , num) ; 
        }


        sort(begin(temp)  , end(temp)) ; 
        

        vector<int>result ; 

        for(pair<int , int>p : temp){
            result.push_back(p.second) ;
        }

        return result ; 
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {4,5,4};
    vector<int> nums2 = {3,6,5,8};

    vector<vector<int>> testCases = {nums1, nums2};

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> result = obj.sortByReflection(testCases[i]);

        cout << "Test Case " << i + 1 << ": ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    return 0;
}
