#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

        bool checkValid(unordered_map<char , int >&freq ){

        int prevFreq = -1 ; 
        for(pair <int , int> p : freq){

            char ch = p.first ; 
            int count = p.second ; 

            if(prevFreq == -1) prevFreq = count ; 

            if(prevFreq != count)
            return false ; 

        }

        return true ; 

    }
    int longestBalanced(string s){
        
        int n = s.length() ; 
        int result = INT_MIN ; 

        for (int i = 0; i < n; i++){
            
            unordered_map<char , int>freq ;

            for(int j = i ; j < n ; j ++ ){
                
                
                freq[s[j] ] ++ ;

                if(checkValid(freq )){
                    result = max(result , j - i + 1 ) ; 
                }
            }
        }

        return result ; 
        
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "abbac";
    cout << "Output: " << sol.longestBalanced(s1)
         << " | Expected: 4" << endl;

    // Example 2
    string s2 = "zzabccy";
    cout << "Output: " << sol.longestBalanced(s2)
         << " | Expected: 4" << endl;

    // Example 3
    string s3 = "aba";
    cout << "Output: " << sol.longestBalanced(s3)
         << " | Expected: 2" << endl;

    return 0;

}


// Time Complexity : O(n^2)
// Space Complexity : O( 1 )
