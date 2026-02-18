#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkAlternatingBits(bitset<32>bt , int idx , bool value){

        for(int i = idx ; i < 32  ; i ++ ){
            if(bt[i] != value){
                return false ; 
            }
        }

        return true ; 

    }
    bool hasAlternatingBits(int n){

        bitset<32>bt(n) ;

        int sameBitIndex = -1 ;

        for(int i = 0 ; i < 32 ; i ++ ){
            
            if(bt[i] == bt[i+1]  ){
                return checkAlternatingBits(bt , i , bt[i]) ? true : false ; 
            }
           
        }

        return false ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Output: " << sol.hasAlternatingBits(5)
         << " | Expected: 1" << endl;   // 5 -> 101 (true)

    // Example 2
    cout << "Output: " << sol.hasAlternatingBits(7)
         << " | Expected: 0" << endl;   // 7 -> 111 (false)

    // Example 3
    cout << "Output: " << sol.hasAlternatingBits(11)
         << " | Expected: 0" << endl;   // 11 -> 1011 (false)

    // Example 4
    cout << "Output: " << sol.hasAlternatingBits(10)
         << " | Expected: 1" << endl;   // 10 -> 1010 (true)

    return 0;
}
