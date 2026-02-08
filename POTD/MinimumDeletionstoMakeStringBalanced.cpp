/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {

       stack<int>st ; 
       int count = 0 ; 

       for(char ch : s ){
        if(!st.empty() && (ch == 'a' && st.top() == 'b')){
            st.pop() ; 
            count ++ ; 
        }else{
            st.push(ch) ; 
        }
       }

       return count ; 
    }
};

int main() {
    Solution sol;

    // Hard-coded test cases
    vector<string> testCases = {
        "aababbab",
        "bbaaaaabb"
    };

    vector<int> expectedOutputs = {
        2,
        2
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << endl;
        cout << "Input: " << testCases[i] << endl;
        cout << "Expected Output: " << expectedOutputs[i] << endl;
        cout << "----------------------------------" << endl;
    }

    return 0;
}

 Time Complexity : O(n)
 Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {


        int left_count_b = 0 ; 
        int right_count_a  = 0 ; 

        for(char ch : s){
            if(ch == 'a') right_count_a ++ ; 
        }

        
        int result = right_count_a ; 

        if(right_count_a == s.length() || right_count_a == 0) 
        return 0 ; 

        for(char ch : s ){

            ch == 'a' ? right_count_a -- : left_count_b ++ ; 
            
            result = min(result , left_count_b + right_count_a) ;

        }

        return result ; 
    }
};

int main() {
    Solution sol;

    // Hard-coded test cases
    vector<string> testCases = {
        "aababbab",
        "bbaaaaabb"
    };

    vector<int> expectedOutputs = {
        2,
        2
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << endl;
        cout << "Input: " << testCases[i] << endl;
        cout << "Expected Output: " << expectedOutputs[i] << endl;
        cout << "----------------------------------" << endl;
    }

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1)



