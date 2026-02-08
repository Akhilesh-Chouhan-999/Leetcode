#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {

        int n = technique1.size() ; 

        long long maxPoints = 0 ; 
        long long tech1 = 0 ; 
        vector<int>diff ; 

        for(int i = 0 ; i < n ; i ++){

            if(technique1[i] >= technique2[i]){
                tech1 ++ ; 
                maxPoints += technique1[i] ; 
            }
            else{
                diff.push_back(technique2[i] - technique1[i]) ; 
                maxPoints += technique2[i] ; 
            }
        }

        if(tech1 >= k ) return maxPoints ; 

        sort(begin(diff) , end(diff)) ; 

        for(int i = 0 ; i < (k - tech1)  ; i ++ )
        {
            maxPoints -= diff[i] ; 
        }

        return maxPoints ; 

    }
};

int main() {
    Solution obj;

    // -------- Testcase 1 --------
    vector<int> t1_1 = {5, 2, 10};
    vector<int> t2_1 = {10, 3, 8};
    int k1 = 2;
    cout << "Testcase 1 Output: " 
         << obj.maxPoints(t1_1, t2_1, k1) << endl;

    // -------- Testcase 2 --------
    vector<int> t1_2 = {10, 20, 30};
    vector<int> t2_2 = {5, 15, 25};
    int k2 = 2;
    cout << "Testcase 2 Output: " 
         << obj.maxPoints(t1_2, t2_2, k2) << endl;

    // -------- Testcase 3 --------
    vector<int> t1_3 = {1, 2, 3};
    vector<int> t2_3 = {4, 5, 6};
    int k3 = 0;
    cout << "Testcase 3 Output: " 
         << obj.maxPoints(t1_3, t2_3, k3) << endl;

    // -------- Testcase 4 (Custom) --------
    vector<int> t1_4 = {7, 1, 9, 3};
    vector<int> t2_4 = {5, 12, 4, 8};
    int k4 = 1;
    cout << "Testcase 4 Output: " 
         << obj.maxPoints(t1_4, t2_4, k4) << endl;

    // -------- Testcase 5 (Custom) --------
    vector<int> t1_5 = {8, 6, 5, 9};
    vector<int> t2_5 = {10, 2, 12, 1};
    int k5 = 3;
    cout << "Testcase 5 Output: " 
         << obj.maxPoints(t1_5, t2_5, k5) << endl;

    return 0;
}


// Time Complexity: n(log(n))