#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums){
           unordered_map<int , int>mpp ;

        int x = 101 ; 
        for(int num : nums){
            mpp[num] ++ ;
            x = min(x , num) ;  
        }
        int y = 101 ; 

        for(int num : nums){

            if(num != x && mpp[num] != mpp[x]){
                y = min(y , num) ; 
            }
        }

        if(y == 101)
        return {-1 , -1} ; 

        return { x , y } ; 

    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,1,2,2,3,4};
    vector<int> res1 = sol.minDistinctFreqPair(nums1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [1, 3]" << endl;

    // Example 2
    vector<int> nums2 = {1,5};
    vector<int> res2 = sol.minDistinctFreqPair(nums2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [-1, -1]" << endl;

    // Example 3
    vector<int> nums3 = {7};
    vector<int> res3 = sol.minDistinctFreqPair(nums3);
    cout << "Output: ";
    printVector(res3);
    cout << " | Expected: [-1, -1]" << endl;

    return 0;
}