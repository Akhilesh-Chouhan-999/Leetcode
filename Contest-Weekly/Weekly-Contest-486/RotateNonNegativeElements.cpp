#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        int n = nums.size() ;

        vector<int>temp ; 

        for(int num : nums){
            if(num >= 0){
                temp.push_back(num) ; 
            }
        }

        k = k % temp.size() ; 

        reverse(temp.begin() , temp.begin() + k) ; 
        reverse(temp.begin()  + k , temp.end()) ;
        reverse(temp.begin()  ,temp.end() ) ; 


        vector<int>result ; 

        int index = 0 ; 
        for(int &num : nums){
            if( num >= 0){
               result.push_back(temp[index] ) ;
               index ++ ; 
            }else{
                result.push_back(num) ; 
            }
        }

        return result ; 

    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, -2, 3, -4};
    int k1 = 3;
    vector<int> result1 = sol.rotateElements(nums1, k1);
    cout << "Output 1: ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {-3, -2, 7};
    int k2 = 1;
    vector<int> result2 = sol.rotateElements(nums2, k2);
    cout << "Output 2: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {5, 4, -9, 6};
    int k3 = 2;
    vector<int> result3 = sol.rotateElements(nums3, k3);
    cout << "Output 3: ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
