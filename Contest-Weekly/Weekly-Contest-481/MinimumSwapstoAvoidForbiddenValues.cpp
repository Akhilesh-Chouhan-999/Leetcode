#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        
       int n = nums.size() ; 
        int result = 0 ; 

        unordered_map<int,int>numsCount , forbiddenCount ; 

        for(int i = 0 ; i < n ; i ++){
            numsCount[nums[i]] ++ ; 
            forbiddenCount[forbidden[i]] ++ ; 
        }

        for(auto &x : numsCount){
            if(numsCount[x.first] > n - forbiddenCount[x.first]){
                return -1 ; 
            }
        }

        int badCount = 0 ; 

        unordered_map<int , int>mpp ; 

        for(int i = 0 ; i < n  ; i ++){
            int num = nums[i] ; 
            int forb = forbidden[i] ;

            if(num == forb){
                badCount++ ; 
                mpp[num] ++ ; 
            }
        }

        if(badCount == 0) return 0 ; 

        int maxBadFreq = 0 ; 

    
        for(auto &p : mpp){
            maxBadFreq = max(maxBadFreq , p.second) ; 
        }

        return max(maxBadFreq , (badCount + 1) / 2) ; 

    }
};

int main() {
    Solution sol;

    vector<vector<int>> numsList = {
        {1, 2, 3},
        {4, 6, 6, 5},
        {7, 7},
        {1, 2}
    };

    vector<vector<int>> forbiddenList = {
        {3, 2, 1},
        {4, 6, 5, 5},
        {8, 7},
        {2, 1}
    };

    vector<int> expected = {1, 2, -1, 0};

    for (int i = 0; i < numsList.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "nums = ";
        for (int x : numsList[i]) cout << x << " ";
        cout << "\nforbidden = ";
        for (int x : forbiddenList[i]) cout << x << " ";
        cout << "\nExpected Output: " << expected[i] << "\n\n";
    }

    return 0;
}
