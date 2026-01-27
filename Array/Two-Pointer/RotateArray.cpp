/*
#include<bits/stdc++.h>
using namespace std ;   


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size() ; 

        k = k % n ; 

        vector<int>temp ;

        int i = 1 ; 

        while( k -- ){
            temp.push_back(nums[n-i]) ;
            i ++ ; 
        }

        reverse(temp.begin() , temp.end()) ; 

        int size = temp.size()  ;

        for(int i = 0 ; i < n - size ; i ++){ 
            temp.push_back(nums[i]) ; 
        }

        nums = temp ; 
        
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    sol.rotate(nums1, k1);
    cout << "Output 1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    sol.rotate(nums2, k2);
    cout << "Output 2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {10};
    int k3 = 5;
    sol.rotate(nums3, k3);
    cout << "Output 3: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}


*/


#include<bits/stdc++.h>
using namespace std ;   


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size() ; 

        k = k % n ; 

        reverse(begin(nums) , end(nums)) ; 
        reverse(begin(nums) , begin(nums) + k ) ; 
        reverse(begin(nums) + k , nums.end()) ; 

    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    sol.rotate(nums1, k1);
    cout << "Output 1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    sol.rotate(nums2, k2);
    cout << "Output 2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {10};
    int k3 = 5;
    sol.rotate(nums3, k3);
    cout << "Output 3: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}
