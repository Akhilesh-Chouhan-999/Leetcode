#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
       
        int n = nums.size() ; 


        for(int i = 0 ; i < k ; i ++){
            
        }

    }
};

int main() {
    Solution obj;

    // -------- Testcase 1 --------
    vector<int> a1 = {3, 1, 2};
    int k1 = 1;
    cout << "Testcase 1 Output: "
         << obj.minInversionCount(a1, k1) << endl;

    // -------- Testcase 2 --------
    vector<int> a2 = {5, 4, 3, 2, 1};
    int k2 = 2;
    cout << "Testcase 2 Output: "
         << obj.minInversionCount(a2, k2) << endl;

    // -------- Testcase 3 --------
    vector<int> a3 = {1, 2, 3, 4};
    int k3 = 0;
    cout << "Testcase 3 Output: "
         << obj.minInversionCount(a3, k3) << endl;

    // -------- Testcase 4 --------
    vector<int> a4 = {2, 1, 3, 1, 2};
    int k4 = 3;
    cout << "Testcase 4 Output: "
         << obj.minInversionCount(a4, k4) << endl;

    // -------- Testcase 5 --------
    vector<int> a5 = {7, 6, 5, 4, 3, 2, 1};
    int k5 = 4;
    cout << "Testcase 5 Output: "
         << obj.minInversionCount(a5, k5) << endl;

    // -------- Testcase 6 (Extra) --------
    vector<int> a6 = {1, 3, 2, 5, 4};
    int k6 = 2;
    cout << "Testcase 6 Output: "
         << obj.minInversionCount(a6, k6) << endl;

    return 0;
}
