#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size() ;
    
        for(int i = n - 1 ; i >= 0 ; i -- ){

            digits[i] += 1 ; 

            if(digits[i] < 10 ){
                return digits ; 
            }

            digits[i] = 0 ; 
        }


        digits.insert(digits.begin() , 1) ; 

        return digits ; 
      

    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = sol.plusOne(digits1);
    for(int x : result1) cout << x << " ";
    cout << endl;

    // Test case 2
    vector<int> digits2 = {9, 9, 9};
    vector<int> result2 = sol.plusOne(digits2);
    for(int x : result2) cout << x << " ";
    cout << endl;

    // Test case 3
    vector<int> digits3 = {4, 3, 2, 1};
    vector<int> result3 = sol.plusOne(digits3);
    for(int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)