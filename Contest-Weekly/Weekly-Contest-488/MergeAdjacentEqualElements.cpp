#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        int n = nums.size() ; 

        stack<long long>st ; 

        for(int &num : nums){

            if(!st.empty() && (st.top() == num)){
                long long temp = num ; 
                while(!st.empty() && ( st.top() == temp)){
                    st.pop() ; 
                    temp = 2 * temp ; 
                }

                st.push(temp) ; 
                
            }else{
                st.push(num) ; 
            }
        }

        vector<long long> result ; 

        while(!st.empty()){
            result.push_back(st.top()) ; 
            st.pop() ; 
        }

        reverse(begin(result) , end(result)) ; 

        return result ; 
    }
};

void printVector(const vector<long long>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> nums1 = {3, 1, 1, 2};
    auto res1 = sol.mergeAdjacent(nums1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [3,4]" << endl;

    // ---------- Example 2 ----------
    vector<int> nums2 = {2, 2, 4};
    auto res2 = sol.mergeAdjacent(nums2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [8]" << endl;

    // ---------- Example 3 ----------
    vector<int> nums3 = {3, 7, 5};
    auto res3 = sol.mergeAdjacent(nums3);
    cout << "Output: ";
    printVector(res3);
    cout << " | Expected: [3,7,5]" << endl;

    return 0;
}
