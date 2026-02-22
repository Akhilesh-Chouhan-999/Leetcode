#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumXor(string s, string t){

        int n = s.length() ; 

        int countZero = 0 ; 
        int countOne = 0 ; 

        for(char ch : t){
            ch == '0' ? countZero ++ : countOne ++ ; 
        }

        int idx = 0 ; 
        string result = "" ; 

        for(char ch : s){

            if(ch == '1'){
                
                if(countZero > 0){
                    result += '1' ; 
                    countZero -- ; 
                } 
                else{
                    result += '0' ;
                    countOne -- ; 
                }
            }
            else{
                if(countOne > 0){
                    result += '1' ; 
                    countOne -- ; 
                }
                else{
                    result += '0' ; 
                    countZero -- ; 
                }
            }
        }
    
        cout << result << endl; 

        
        return result ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "101";
    string t1 = "011";
    cout << "Output: " << sol.maximumXor(s1, t1)
         << " | Expected: 110" << endl;

    // Example 2
    string s2 = "0110";
    string t2 = "1110";
    cout << "Output: " << sol.maximumXor(s2, t2)
         << " | Expected: 1101" << endl;

    // Example 3
    string s3 = "0101";
    string t3 = "1001";
    cout << "Output: " << sol.maximumXor(s3, t3)
         << " | Expected: 1111" << endl;

    return 0;
}