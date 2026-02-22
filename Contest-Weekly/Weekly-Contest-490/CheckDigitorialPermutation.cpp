#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
   unordered_map<int , int> genFreq(int num){

    unordered_map<int , int> mpp; 

    if(num == 0) {
        mpp[0]++;
        return mpp;
    }

    while(num){
        mpp[num % 10]++;
        num /= 10;  
    }

    return mpp; 
   
    }

    bool isDigitorialPermutation(int n) {
        
        unordered_map<int, int> factorial = {
            {0, 1}, {1, 1}, {2, 2}, {3, 6}, {4, 24},
            {5, 120}, {6, 720}, {7, 5040},
            {8, 40320}, {9, 362880}
        };

        int sum = 0; 
        int num = n; 

        while(n){
            sum += factorial[n % 10]; 
            n /= 10; 
        }

        return genFreq(num) == genFreq(sum); 
    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.isDigitorialPermutation(145)
         << " | Expected: 1" << endl;

    // Example 2
    cout << "Output: " << sol.isDigitorialPermutation(10)
         << " | Expected: 0" << endl;

    // Additional Test
    cout << "Output: " << sol.isDigitorialPermutation(40585)
         << " | Expected: 1" << endl;

    return 0;
}