#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int vowelCount = -1 ; 

    int count(string s ) {
        int cnt = 0 ; 
        for(char &ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                cnt ++ ; 
        }
        return cnt ; 
    }
    
    string reverseWords(string s) {

        stringstream ss(s) ;
        string token ; 
        string result = "" ; 
  
        while(getline(ss , token , ' ')){
            if(vowelCount == -1){
                vowelCount = count(token) ; 
                result += token ; 
            }
            else if(count(token) == vowelCount){
                reverse(token.begin() , token.end()) ; 
                result += token ; 
            }
            else {
                result += token ; 
            }
            
            result += ' ' ; 

        }

        result.pop_back() ; 
        return result ; 
    }
};

int main() {
    Solution obj;

    string s1 = "hello world apple code";
    cout << "Input:  " << s1 << endl;
    cout << "Output: " << obj.reverseWords(s1) << endl;

    cout << endl;

    Solution obj2;  // fresh object because vowelCount is class-level
    string s2 = "ae bc de fg";
    cout << "Input:  " << s2 << endl;
    cout << "Output: " << obj2.reverseWords(s2) << endl;

    return 0;
}
